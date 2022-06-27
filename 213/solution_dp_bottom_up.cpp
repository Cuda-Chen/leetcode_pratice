// DP (botton-up)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return n == 0 ? 0 : nums[0];
        return max(rob(nums, 0, n - 1),
                   rob(nums, 1, n));
    }
    
private:
    int rob(vector<int> &nums, int l, int r) {
        if(r - l <= 1)
            return nums[l];
        vector<int> dp(r);
        dp[l] = nums[l];
        dp[l + 1] = max(nums[l], nums[l + 1]);
        for(int i = l + 2; i < r; i++)
            dp[i] = max(dp[i - 1],
                        dp[i - 2] + nums[i]);
        return dp[r - 1];
    }
};
