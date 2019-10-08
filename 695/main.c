int DFS(int **grid, int gridSize, int *gridColSize, int i, int j);
inline int max(int a, int b) {
    return a > b ? a : b;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int maxArea = 0;
    
    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < *gridColSize; j++) {
            maxArea = max(maxArea, DFS(grid, gridSize, gridColSize, i, j));
        }
    }
    
    return maxArea;
}

int DFS(int **grid, int gridSize, int *gridColSize, int i, int j) {
    if(i < 0 || j < 0 || i > gridSize - 1 || j > *gridColSize - 1 || grid[i][j] == 0) {
        return 0;
    }
    
    grid[i][j] = 0;
    
    return 1 + 
        DFS(grid, gridSize, gridColSize, i - 1, j) +
        DFS(grid, gridSize, gridColSize, i + 1, j) + 
        DFS(grid, gridSize, gridColSize, i, j - 1) +
        DFS(grid, gridSize, gridColSize, i, j + 1);
}


