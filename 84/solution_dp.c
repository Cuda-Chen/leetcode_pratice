// DP

int min(const int a, const int b) {
    return a < b ? a : b;
}

int max(const int a, const int b) {
    return a > b ? a : b;
}

int largestRectangleArea(int* heights, int heightsSize){
    int n = heightsSize;
    int result = 0;
    
    for(int i = 0; i < n; i++) {
        if(i + 1 < n && heights[i] <= heights[i + 1]) {
            continue;
        }
        
        int h = heights[i], w;
        for(int j = i; j >= 0; j--) {
            h = min(h, heights[j]);
            w = i - j + 1;
            result = max(result, h * w);
        }
    }
    
    return result;
}
