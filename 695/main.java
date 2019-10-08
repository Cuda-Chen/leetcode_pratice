class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int maxArea = 0;
        
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[0].length; j++) {
                maxArea = Math.max(maxArea, DFS(grid, i, j));
            }
        }
        
        return maxArea;
    }
    
    public int DFS(int[][] grid, int i, int j) {
        if(i < 0 || j < 0 || i > grid.length - 1 || j > grid[0].length - 1 || grid[i][j] == 0) {
            return 0;
        }
        
        grid[i][j] = 0;
        
        return 1 + 
            DFS(grid, i - 1, j) +
            DFS(grid, i + 1, j) + 
            DFS(grid, i, j - 1) +
            DFS(grid, i, j + 1);
    }
}
