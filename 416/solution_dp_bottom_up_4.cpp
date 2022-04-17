// DP (bottom-up)
// Use integer DP table.

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if(sum & 1) return false;
        sum >>= 1;
        int n = nums.size();
        vector<int> dp(sum + 1);
        dp[0] = 1;
        
        for(int i = 0; i < n; i++) {
            for(int j = sum; j >= 0; j--) {
                if(j - nums[i] >= 0)
                    dp[j] = max(dp[j], dp[j - nums[i]]);
            }
        }
        
        return dp[sum];
    }
};
