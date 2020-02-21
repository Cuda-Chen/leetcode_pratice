// DFS + memorization

inline int max(const int a, const int b) {
    return a > b ? a : b;
}

int DFS(int** matrix, int i, int j, int n, int m, int** dp);

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize){
    int result = 0;
    if(matrixSize <= 0 || *matrixColSize <= 0) {
        return result;
    }
    int n = matrixSize, m = *matrixColSize;
    int** dp;
    dp = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i < n; i++) {
        dp[i] = (int *)malloc(sizeof(int) * m);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp[i][j] = -1;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            result = max(result, DFS(matrix, i, j, n, m, dp));
        }
    }
    
    return result;
}

int DFS(int** matrix, int i, int j, int n, int m, int** dp) {
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    
    static int dirs[] = {0, 1, 0, -1, 0};
    dp[i][j] = 1;
    for(int k = 0; k < 4; k++) {
        int x = i + dirs[k], y = j + dirs[k + 1];
        if(x < 0 || y < 0 || x >= n || y >= m || matrix[x][y] <= matrix[i][j]) {
            continue;
        }
        dp[i][j] = max(dp[i][j], 1 + DFS(matrix, x, y, n, m, dp));
    }
    
    return dp[i][j];
}


