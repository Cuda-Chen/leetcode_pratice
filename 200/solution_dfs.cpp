// DFS

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        if(grid.empty() || grid[0].empty()) {
            return result;
        }
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    result++;
                    DFS(grid, i, j, n, m, visited);
                }
            }
        }
        
        return result;
    }
    
private:
    int xDir[4] = {1, -1, 0, 0};
    int yDir[4] = {0, 0, 1, -1};
    
    void DFS(vector<vector<char>> &grid, int i, int j, int n, int m, vector<vector<bool>> &visited) {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0' || visited[i][j]) {
            return;
        }
        
        visited[i][j] = true;
        for(int k = 0; k < 4; k++) {
            DFS(grid, i + xDir[k], j + yDir[k], n, m, visited);
        }
    }
};
