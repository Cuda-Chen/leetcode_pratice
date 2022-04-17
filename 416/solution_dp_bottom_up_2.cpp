// https://labuladong.gitee.io/algo/3/26/82/
// DP (bottom-up, optimized)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if(sum & 1) return false;
        sum >>= 1;
        int n = nums.size();
        vector<bool> dp(sum + 1);
        dp[0] = true;

        for(int i = 0; i < n; i++) {
            for(int j = sum; j >= 0; j--) {
                if(j - nums[i] >= 0)
                    dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[sum];
    }
};
