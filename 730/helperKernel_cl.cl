__kernel void helperKernel(__global char *S, __global int *dp, int n, long kMod, int len) {
    int i = get_global_id(0);

    if(i < n - len) {
        int j = i + len;
  
        if(S[i] == S[j]) {
            dp[i * n + j] = dp[(i + 1) * n + (j - 1)] * 2;
            int left = i + 1;
            int right = j - 1;

            while(left <= right && S[left] != S[i]) {
                left++;
            }
            while(left <= right && S[right] != S[i]) {
                right--;
            }

            if(left == right) {
                dp[i * n + j] += 1;
            } else if(left > right) {  
                dp[i * n + j] += 2;
            } else {
                dp[i * n + j] -= dp[(left + 1) * n + (right - 1)];
            }
        } else {
            dp[i * n + j] = dp[i * n + (j - 1)] + dp[(i + 1) * n + j] - dp[(i + 1) * n + (j - 1)];
        }

        dp[i * n + j] = (dp[i * n + j] + kMod) % kMod; // perform positive modulo
    }
}
