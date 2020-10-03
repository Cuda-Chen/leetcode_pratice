// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-410-split-array-largest-sum/
// DP (bottom-up)

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> sums(n);
        // dp[i][j] := min of largest sum of nums[0] ~ nums[j] into i groups
        vector<vector<int>> dp(m + 1, vector<int>(n, INT_MAX));
        sums[0] = nums[0];
        for(int i = 1; i < n; i++)
            sums[i] = sums[i - 1] + nums[i];
        for(int i = 0; i < n; i++)
            dp[1][i] = sums[i];
        
        for(int i = 2; i <= m; i++)
            for(int j = i - 1; j < n; j++)
                for(int k = 0; k < j; k++)
                    dp[i][j] = min(max(dp[i - 1][k], sums[j] - sums[k]), dp[i][j]);
        return dp[m][n - 1];
    }
};
