// DP (top-down)

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp = vector<vector<int>>(n, vector<int>(n, INT_MIN));
        return helper(piles, 0, n - 1);
    }
    
private:
    vector<vector<int>> dp;
    
    int helper(vector<int> &piles, int i, int j) {
        if(i == j)
            dp[i][j] = piles[i];
        if(dp[i][j] == INT_MIN)
            dp[i][j] = max(piles[i] - helper(piles, i + 1, j),
                           piles[j] - helper(piles, i, j - 1));
        return dp[i][j];
    }
};
