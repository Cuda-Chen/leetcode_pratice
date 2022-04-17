// DP (bottom-up)
// Use integer DP table.

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if(sum & 1) return false;
        sum >>= 1;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                if(j - nums[i - 1] < 0)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j],
                                   dp[i - 1][j - nums[i - 1]]);
            }
        }

        return dp[n][sum];
    }
};
