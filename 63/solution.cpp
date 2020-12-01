// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-63-unique-paths-ii/
// DP (top-down)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if(n <= 0) return 0;
        int m = obstacleGrid[0].size();
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, INT_MIN));
        return paths(m, n, obstacleGrid);
    }
    
private:
    vector<vector<int>> dp;
    int paths(int x, int y, vector<vector<int>> &o) {
        if(x <= 0 || y <= 0) return 0;
        
        if(x == 1 && y == 1) return 1 - o[0][0];
        
        if(dp[y][x] != INT_MIN) return dp[y][x];
        
        if(o[y - 1][x - 1] == 1)
            dp[y][x] = 0;
        else
            dp[y][x] = paths(x - 1, y, o) + paths(x, y - 1, o);
        
        return dp[y][x];
    }
};
