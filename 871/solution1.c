// 0/1 knapsack problem

int max(const int a, const int b) {
    return a > b ? a : b;
}

int minRefuelStops(int target, int startFuel, int** stations, int stationsSize, int* stationsColSize){
    int n = stationsSize;
    long *dp = (long *)malloc(sizeof(long) * (n + 1));
    for(int i = 0; i <= n; i++) {
        dp[i] = startFuel;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j >= 1; j--) {
            if(dp[j - 1] >= stations[i][0]) {
                dp[j] = max(dp[j], dp[j - 1] + stations[i][1]);
            }
        }
    }
    
    for(int i = 0; i <= n; i++) {
        if(dp[i] >= target) {
            return i;
        }
    }
    
    return -1;
}
