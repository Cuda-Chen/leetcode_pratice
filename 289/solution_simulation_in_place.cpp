// simulation (in-place)
// Use two temp value to represent the transition

class Solution {
public:
    void gameOfLife(vector<vector<int>>& dp) {
        int n = dp.size(), m = dp[0].size();
        vector<vector<int>> d{
            {0, 1}, {1, 0},
            {0, -1}, {-1, 0},
            {1, 1}, {1, -1},
            {-1, 1}, {-1, -1}
        };
        
        // 2: 0 -> 1, 3: 1 -> 0
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int cnt = 0;
                for(int k = 0; k < d.size(); k++) {
                    int y = i + d[k][0], x = j + d[k][1];
                    if(x < 0 || y < 0 || x >= m || y >= n) {
                        continue;
                    }
                    if(dp[y][x] == 1 || dp[y][x] == 3)
                        cnt++;
                }
                
                if(dp[i][j] == 1) {
                    if(cnt < 2 || cnt > 3)
                        dp[i][j] = 3;
                } else {
                    if(cnt == 3)
                        dp[i][j] = 2;
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dp[i][j] == 2)
                    dp[i][j] = 1;
                else if(dp[i][j] == 3)
                    dp[i][j] = 0;
            }
        }
    }
};
