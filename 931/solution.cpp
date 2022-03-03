// DP (bottom-up)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n + 2, vector<int>(m + 2));
        
        for(int i = 1; i <= n; i++) {
            dp[i][0] = dp[i][m + 1] = INT_MAX;
            for(int j = 1; j <= m; j++) {
                dp[i][j] = *min_element(
                    dp[i - 1].begin() + j - 1,
                    dp[i - 1].begin() + j + 2
                ) + matrix[i - 1][j - 1];
            }
        }
        
        return *min_element(dp[n].begin() + 1, dp[n].end() - 1);
    }
};
