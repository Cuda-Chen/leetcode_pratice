#define TS 4

__kernel void helperKernel(__global char *S, __global int *dp, int n, long kMod, int len) {
    int ii = get_local_id(0);
    int i = TS * get_group_id(0) + ii;
    __local int tmp_a[TS];
    __local int tmp_b[TS];
    __local int tmp_c[TS];

    if(i < n - len) {
        int j = i + len;

        unsigned int mask_eq = (S[i] == S[j]) ? 0xFFFFFFFF : 0x0;
        unsigned int mask_neq = (S[i] != S[j]) ? 0xFFFFFFFF : 0x0;
        int tmp = 0;

        tmp += (unsigned int)(dp[(i + 1) * n + (j - 1)] * 2) & mask_eq;
        int l = i + 1, r = j - 1;
        while(l <= r && S[l] != S[i])
            l++;
        while(l <= r && S[r] != S[i])
            r--;
        if(l == r)
            tmp += 1 & mask_eq;
        else if(l > r)
            tmp += 2 & mask_eq;
        else
            tmp -= (unsigned int)dp[(l + 1) * n + (r - 1)] & mask_eq; 
        tmp += (unsigned int)(dp[i * n + (j - 1)] + dp[(i + 1) * n + j] - dp[(i + 1) * n + (j - 1)]) & mask_neq;
        
        tmp = (tmp + kMod) % kMod; // perform positive modulo

        dp[i * n + j] = (int)tmp;
    }
}
