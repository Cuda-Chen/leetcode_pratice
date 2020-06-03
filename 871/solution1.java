// 0/1 knapsack problem

class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        int n = stations.length;
        long[] dp = new long[n + 1];
        for(int i = 0; i < dp.length; i++) {
            dp[i] = startFuel;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j >= 1; j--) {
                if(dp[j - 1] >= stations[i][0]) {
                    dp[j] = Math.max(dp[j], dp[j - 1] + stations[i][1]);
                }
            }
        }
        
        for(int i = 0; i < dp.length; i++) {
            if(dp[i] >= target) {
                return i;
            }
        }
        
        return -1;
    }
}
