// monotonic stack

int max(const int a, const int b) {
    return a > b ? a : b;
}

int largestRectangleArea(int* heights, int heightsSize){
    int n = heightsSize + 1;
    int i;
    int *heights_copy = (int *)malloc(sizeof(int) * n);
    for(i = 0; i < n - 1; i++) {
        heights_copy[i] = heights[i];
    }
    heights_copy[n - 1] = 0;
    int s[100000], s_top = -1;
    int result = 0;
    
    i = 0;
    while(i < n) {
        if(s_top == -1 || heights_copy[i] >= heights_copy[s[s_top]]) {
            s_top++;
            s[s_top] = i;
            i++;
        } else {
            int h = heights_copy[s[s_top]]; s_top--;
            int w = s_top == -1 ? i : i - s[s_top] - 1;
            result = max(result, h * w);
        }
    }
    
    free(heights_copy);
    
    return result;
}
