// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-174-dungeon-game/
// DP (O(n) space)

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n - 1] = 1;
        
        for(int y = m - 1; y >= 0; y--) {
            for(int x = n - 1; x >= 0; x--) {
                dp[x] = max(1, min(dp[x], dp[x + 1]) - dungeon[y][x]);
            }
        }
        
        return dp[0];
    }
};
