// https://www.cnblogs.com/grandyang/p/5138186.html
// DP (bottom-up)
// Sometimes get TLE in 2022.

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int coin : coins) {
            for(int i = amount - coin; i >= 0; i--) {
                if(dp[i] != INT_MAX) {
                    for(int k = 1; k * coin + i <= amount; k++)
                        dp[k * coin + i] = min(dp[k * coin + i], dp[i] + k);
                }
            }
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};
