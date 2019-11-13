int cmp(const void *a, const void *b) {
    int va = *(const int *)a;
    int vb = *(const int *)b;
    return (va > vb) - (va < vb);
}

int heightChecker(int* heights, int heightsSize){
    int n = heightsSize;
    int rightPosition[n];
    for(int i = 0; i < n; i++) {
        rightPosition[i] = heights[i];
    }
    
    qsort(rightPosition, n, sizeof(int), cmp);
    
    int result = 0;
    for(int i = 0; i < n; i++) {
        if(rightPosition[i] != heights[i]) {
            result++;
        }
    }
    
    return result;
}
