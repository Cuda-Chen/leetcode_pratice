// DP (bottom-up)

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        for(int i = 0; i < n; i++)
            dp[i][i] = piles[i];
        
        for(int l = 2; l <= n; l++) {
            for(int i = 0; i < n - l + 1; i++) {
                int j = i + l - 1;
                dp[i][j] = max(piles[i] - dp[i + 1][j],
                               piles[j] - dp[i][j - 1]);
            }
        }
        
        return dp[0][n - 1];
    }
};
