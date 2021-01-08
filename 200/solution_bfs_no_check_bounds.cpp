// BFS w/o check bounds

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        if(grid.size() == 0 || grid[0].size() == 0) return result;
        int n = grid.size() + 2, m = grid[0].size() + 2;
        int xDir[] = {1, -1, 0, 0}, yDir[] = {0, 0, 1, -1};
        
        for(vector<char> &v : grid) {
            v.insert(v.begin(), '0');
            v.insert(v.end(), '0');
        }
        
        vector<char> temp(m, '0');
        grid.insert(grid.begin(), temp);
        grid.insert(grid.end(), temp);
        
        for(int i = 1; i < n - 1; i++) {
            for(int j = 1; j < m - 1; j++) {
                if(grid[i][j] == '0') continue;
                
                result++;
                queue<int> q{{i * m + j}};
                while(!q.empty()) {
                    int temp = q.front(); q.pop();
                    for(int k = 0; k < 4; k++) {
                        int x = temp / m + xDir[k], y = temp % m + yDir[k];
                        if(grid[x][y] == '0') continue;
                        grid[x][y] = '0';
                        q.push(x * m + y);
                    }
                }
            }
        }
        
        return result;
    }
};
