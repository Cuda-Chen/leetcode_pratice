class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                maxArea = max(maxArea, DFS(grid, i, j));
            }
        }
        
        return maxArea;
    }
    
    int DFS(vector<vector<int>> &grid, int i, int j) {
        if(i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1 || grid[i][j] == 0) {
            return 0;
        }
        
        grid[i][j] = 0;
            
        return (1 + DFS(grid, i - 1, j) + DFS(grid, i + 1, j)
                + DFS(grid, i, j - 1) + DFS(grid, i , j + 1));
    }
};
