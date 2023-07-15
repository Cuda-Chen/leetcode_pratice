#define TS 4

__kernel void helperKernel(__constant char *S, __global int *dp, int n, long kMod, int len) {
    int ii = get_local_id(0);
    int i = TS * get_group_id(0) + ii;
    __local int tmp_a[TS]; // dp[i + 1][j - 1]
    __local int tmp_b[TS]; // dp[i][j - 1]
    __local int tmp_c[TS]; // dp[i + 1][j]
    __local int tmp_d[TS]; // dp[l + 1][r - 1]

    bool in_range = (i < n - len) ? true : false;

    for(int t = 0; t < (TS + n - 1) / TS; t++) {
        int j = i + len;
        int mask_eq = (in_range && S[i] == S[j]) ? 0xFFFFFFFF : 0x0;
        int mask_neq = (in_range && S[i] != S[j]) ? 0xFFFFFFFF : 0x0;

        int l = i + 1, r = j - 1;
        while(mask_eq && l <= r && S[l] != S[i])
            l++;
        while(mask_eq && l <= r && S[r] != S[i])
            r--;

        tmp_a[ii] = in_range ? dp[(i + 1) * n + (j - 1)] : 0;
        tmp_b[ii] = in_range ? dp[i * n + (j - 1)] : 0;
        tmp_c[ii] = in_range ? dp[(i + 1) * n + j] : 0;
        tmp_d[ii] = in_range ? dp[(l + 1) * n + (r - 1)] : 0;
        barrier(CLK_LOCAL_MEM_FENCE);
        int tmp = 0;
        tmp += (tmp_a[ii] * 2) & mask_eq;
        if(l == r)
            tmp += (1 & mask_eq);
        else if(l > r)
            tmp += (2 & mask_eq);
        else
            tmp -= (tmp_d[ii] & mask_eq);
        tmp += (tmp_b[ii] + tmp_c[ii] - tmp_a[ii]) & mask_neq;
        
        tmp = (tmp + kMod) % kMod; // perform positive modulo
        if(in_range)
            dp[i * n + j] = tmp;
        barrier(CLK_LOCAL_MEM_FENCE);
    } 
}
