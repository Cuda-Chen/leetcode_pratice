class Solution:
    def DFS(self, grid: List[List[int]], i: int, j: int) -> int:
        if i < 0 or j < 0 or i > len(grid) - 1 or j > len(grid[0]) - 1 or grid[i][j] == 0:
            return 0
        
        grid[i][j] = 0
        
        return 1 + \
    self.DFS(grid, i - 1, j) + \
    self.DFS(grid, i + 1, j) + \
    self.DFS(grid, i, j - 1) + \
    self.DFS(grid, i, j + 1)
    
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        maxArea = 0
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                maxArea = max(maxArea, self.DFS(grid, i, j))
                
        return maxArea
        
