# DFS + memorization

class Solution: 
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        result = 0
        if not matrix:
            return result
        n, m = len(matrix), len(matrix[0])
        dp = [[-1] * m for _ in range(n)]
        
        for i in range(n):
            for j in range(m):
                result = max(result, self.DFS(matrix, i, j, n, m, dp))
                
        return result
    
    def DFS(self, matrix, i, j, n, m, dp):
        if dp[i][j] != -1:
            return dp[i][j]
        
        dirs = [0, 1, 0, -1, 0]
        dp[i][j] = 1
        for k in range(4):
            x, y = i + dirs[k], j + dirs[k + 1]
            if x < 0 or y < 0 or x >= n or y >= m or matrix[x][y] <= matrix[i][j]:
                continue
                
            dp[i][j] = max(dp[i][j], 1 + self.DFS(matrix, x, y, n, m, dp))
            
        return dp[i][j]
        
