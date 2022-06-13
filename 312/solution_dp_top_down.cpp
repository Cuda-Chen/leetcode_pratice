// DP (top-down)

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        dp = vector<vector<int>>(n + 2, vector<int>(n + 2));

        return helper(nums, 1, n);
    }

private:
    vector<vector<int>> dp;

    int helper(vector<int> &nums, int i, int j) {
        if(i > j)
            return 0;
        else if(i == j)
            return nums[i - 1] * nums[i] * nums[i + 1];
        if(dp[i][j])
            return dp[i][j];

        int ans = 0;
        for(int k = i; k <= j; k++)
            ans = max(ans,
                      helper(nums, i, k - 1) + nums[i - 1] * nums[k] * nums[j + 1] + helper(nums, k + 1, j));
        return dp[i][j] = ans;
    }
};
