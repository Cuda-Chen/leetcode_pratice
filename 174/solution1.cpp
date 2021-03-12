// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-174-dungeon-game/
// DP

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m - 1][n] = dp[m][n - 1] = 1;
        
        for(int y = m - 1; y >= 0; y--) {
            for(int x = n - 1; x >= 0; x--) {
                dp[y][x] = max(1, min(dp[y + 1][x], dp[y][x + 1]) - dungeon[y][x]);
            }
        }
        
        return dp[0][0];
    }
};
