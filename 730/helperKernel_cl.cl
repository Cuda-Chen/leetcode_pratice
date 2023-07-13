#define TS 4

__kernel void helperKernel(__global char *S, __global int *dp, int n, long kMod, int len) {
    int ii = get_local_id(0);
    int i = TS * get_group_id(0) + ii;
    __local int tmp_a[TS]; // dp[i + 1][j - 1]
    __local int tmp_b[TS]; // dp[i][j - 1]
    __local int tmp_c[TS]; // dp[i + 1][j]
    __local int tmp_d[TS]; // dp[l + 1][r - 1]

    bool in_range = (i < n - len) ? true : false;

    for(int t = 0; t < (TS + (n - len) - 1) / TS; t++) {
        int j = i + len;

        int mask_eq = (in_range && S[i] == S[j]) ? 0xFFFFFFFF : 0x0;
        int mask_neq = (in_range && S[i] != S[j]) ? 0xFFFFFFFF : 0x0;
        int tmp = 0;

        tmp += in_range
            ? (dp[(i + 1) * n + (j - 1)] * 2) & mask_eq
            : 0;
        int l = i + 1, r = j - 1;
        while(in_range && l <= r && S[l] != S[i])
            l++;
        while(in_range && l <= r && S[r] != S[i])
            r--;
        if(l == r)
            tmp += 1 & mask_eq;
        else if(l > r)
            tmp += 2 & mask_eq;
        else
            tmp -= in_range
                ? (dp[(l + 1) * n + (r - 1)] & mask_eq)
                : 0; 
        tmp += in_range
            ? (dp[i * n + (j - 1)] + dp[(i + 1) * n + j] - dp[(i + 1) * n + (j - 1)]) & mask_neq
            : 0;
        
        tmp = (tmp + kMod) % kMod; // perform positive modulo

        if(in_range)
            dp[i * n + j] = tmp;
    }

    /*if(i < n - len) {
        int j = i + len;

        int mask_eq = (S[i] == S[j]) ? 0xFFFFFFFF : 0x0;
        int mask_neq = (S[i] != S[j]) ? 0xFFFFFFFF : 0x0;
        int tmp = 0;

        tmp += (dp[(i + 1) * n + (j - 1)] * 2) & mask_eq;
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
            tmp -= dp[(l + 1) * n + (r - 1)] & mask_eq; 
        tmp += (dp[i * n + (j - 1)] + dp[(i + 1) * n + j] - dp[(i + 1) * n + (j - 1)]) & mask_neq;
        
        tmp = (tmp + kMod) % kMod; // perform positive modulo

        dp[i * n + j] = tmp;
    }*/
}
