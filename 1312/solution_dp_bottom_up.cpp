// DP (bottom-up)

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int l = 2; l <= n; l++) {
            for(int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                if(s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1];
                else
                    dp[i][j] = min(dp[i][j - 1],
                                   dp[i + 1][j]) + 1;
            }
        }
        
        return dp[0][n - 1];
    }
};
