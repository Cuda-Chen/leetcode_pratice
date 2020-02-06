// BFS

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        if(grid.empty() || grid[0].empty()) {
            return result;
        }
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        int xDir[] = {1, -1, 0, 0}, yDir[] = {0, 0, 1, -1};
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '0' || visited[i][j]) {
                    continue;
                }
                
                result++; 
                queue<int> q{{i * m + j}};
                while(!q.empty()) {
                    int temp = q.front(); q.pop();
                    for(int k = 0; k < 4; k++) {
                        int x = temp / m + xDir[k], y = temp % m + yDir[k];
                        if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '0' || visited[x][y]) {
                            continue;
                        }
                        visited[x][y] = true;
                        q.push(x * m + y);
                    }
                }
            }
        }
        
        return result;
    }
};
