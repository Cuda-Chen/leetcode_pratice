// DP (bottom-up optimized)

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> dp(piles);
        
        for(int l = 2; l <= n; l++) {
            for(int i = 0; i < n - l + 1; i++) {
                int j = i + l - 1;
                dp[i] = max(piles[i] - dp[i + 1],
                            piles[j] - dp[i]);
            }
        }
        
        return dp[0];
    }
};
