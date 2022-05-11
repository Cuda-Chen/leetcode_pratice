// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-787-cheapest-flights-within-k-stops/
// Bellman-Ford
// O(n) space

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e8;
        vector<vector<int>> dp(k + 2, vector<int>(n, INF));
        dp[0][src] = 0;
        
        for(int i = 1; i <= k + 1; i++) {
            dp[i][src] = 0;
            for(const auto &p : flights)
                dp[i][p[1]] = min(dp[i][p[1]], dp[i - 1][p[0]] + p[2]);
        }
        
        return dp[k + 1][dst] >= INF ? -1 : dp[k + 1][dst];
    }
};
