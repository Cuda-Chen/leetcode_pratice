#define TS 4

__kernel void helperKernel(__global char *S, __global int *dp, int n, long kMod, int len) {
    int ii = get_local_id(0);
    int i = TS * get_group_id(0) + ii;
    __local int tmp_a[TS];
    __local int tmp_b[TS];
    __local int tmp_c[TS];

    if(i < n - len) {
        int j = i + len;

        int mask = (S[i] == S[j]) ? 0x7FFFFFFF : 0x0;
        int tmp = 0;

        if(mask) {
            tmp = dp[(i + 1) * n + (j - 1)] * 2;
            int l = i + 1, r = j - 1;
            while(l <= r && S[l] != S[i])
                l++;
            while(l <= r && S[r] != S[i])
                r--;
            if(l == r)
                tmp += 1;
            else if(l > r)
                tmp += 2;
            else
                tmp -= dp[(l + 1) * n + (r - 1)]; 
        } else
            tmp = dp[i * n + (j - 1)] + dp[(i + 1) * n + j] - dp[(i + 1) * n + (j - 1)];

        /*tmp += ((dp[(i + 1) * n + (j - 1)] * 2) & mask);
        int l = i + 1;
        int r = j - 1;

        while(l <= r && S[l] != S[i])
            l++;
        while(l <= r && S[r] != S[i])
            r--;

        if(l == r)
            tmp += (1 & mask);
        else if(l > r)
            tmp += (2 & mask);
        else
            tmp -= (dp[(l + 1) * n + (r - 1)] & mask);
       
        tmp += dp[i * n + (j - 1)] & !mask;
        tmp += dp[(i + 1) * n + j] & !mask;
        tmp -= dp[(i + 1) * n + (j - 1)] & !mask;*/

        tmp = (tmp + kMod) % kMod; // perform positive modulo

        dp[i * n + j] = (int)tmp;
    }
}
