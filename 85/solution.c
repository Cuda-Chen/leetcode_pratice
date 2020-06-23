// monotonic stack

#define MAX(a, b) a > b ? a : b

int largestRectangle(int *h, int hSize) {
    int n = hSize + 1;
    int *heights = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n - 1; i++) {
        heights[i] = h[i];
    }
    heights[n - 1] = 0;
    int stack[100000]; int s_top = -1;
    int result = 0, i = 0;
    
    while(i < n) {
        if(s_top == -1 || heights[i] > heights[stack[s_top]]) {
            s_top++;
            stack[s_top] = i;
            i++;
        } else {
            int h = heights[stack[s_top]]; s_top--;
            int w = s_top == -1 ? i : i - stack[s_top] - 1;
            result = MAX(result, h * w);
        }
    }
    
    free(heights);
    return result;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    // if input size is smaller than zero
    if(matrixSize <= 0 || *matrixColSize <= 0) {
        return 0;
    }
    
    int *heights = (int *)malloc(sizeof(int) * (*matrixColSize));
    for(int i = 0; i < *matrixColSize; i++) {
        heights[i] = 0;
    }
    int result = 0;
    
    for(int i = 0; i < matrixSize; i++) {
        for(int j = 0; j < *matrixColSize; j++) {
            heights[j] = matrix[i][j] == '0' ? 0 : (1 + heights[j]);
        }
        result = MAX(result, largestRectangle(heights, *matrixColSize));
    }
    
    free(heights);
    return result;
}
