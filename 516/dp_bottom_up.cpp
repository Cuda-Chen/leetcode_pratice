// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-516-longest-palindromic-subsequence/
// DP (bottom-up)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int l = 1; l <= n; l++) {
            for(int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                
                if(i == j) dp[i][j] = 1;
                else if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[0][n - 1];
    }
};
