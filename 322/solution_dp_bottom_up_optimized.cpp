// https://www.cnblogs.com/grandyang/p/5138186.html
// DP (bottom-up, opmized)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int coin : coins) {
            for(int i = coin; i <= amount; i++) {
                if(dp[i - coin] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};
