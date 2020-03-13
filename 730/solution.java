// DP (bottom-up)

class Solution {
    public int countPalindromicSubsequences(String S) {
        int n = S.length();
        int[][] dp = new int[n][n];
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        for(int len = 1; len <= n; len++) {
            for(int i = 0; i < n - len; i++) {
                int j = i + len;
                if(S.charAt(i) == S.charAt(j)) {
                    int left = i + 1, right = j - 1;
                    dp[i][j] = dp[i + 1][j - 1] * 2;
                    while(left <= right && S.charAt(i) != S.charAt(left)) {
                        left++;
                    }
                    while(left <= right && S.charAt(i) != S.charAt(right)) {
                        right--;
                    }
                    
                    if(left == right) {
                        dp[i][j] += 1;
                    } else if(left > right) {
                        dp[i][j] += 2;
                    } else {
                        dp[i][j] -= dp[left + 1][right - 1];
                    }
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                }
                
                dp[i][j] = (int)(((long)dp[i][j] + kMod) % kMod);
            }
        }
        
        return dp[0][n - 1];
    }
    
    private long kMod = 1000000007;
}
