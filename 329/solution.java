// DFS + memorization

class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        int result = 0;
        if(matrix.length <= 0 || matrix[0].length <= 0) {
            return result;
        }
        n = matrix.length;
        m = matrix[0].length;
        int[][] dp = new int[n][m];
        for(int i = 0; i < n; i++)  {
            for(int j = 0; j < m; j++) {
                dp[i][j] = -1;
            }
        }
        
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                result = Math.max(result, DFS(matrix, i, j, dp));
            }
        }
        
        return result;
    }
    
    private int DFS(int[][] matrix, int i, int j, int[][] dp) {
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int[] dirs = {0, 1, 0, -1, 0};
        dp[i][j] = 1;
        for(int k = 0; k < 4; k++) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if(x < 0 || y < 0 || x >= n || y >= m || matrix[x][y] <= matrix[i][j]) {
                continue;
            }
            dp[i][j] = Math.max(dp[i][j], 1 + DFS(matrix, x, y, dp));
        }
        
        return dp[i][j];
    }
    
    private int n, m;
}
