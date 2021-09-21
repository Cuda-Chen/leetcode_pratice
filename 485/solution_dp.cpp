// DP (bottom-up)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = (nums[0] == 0) ? 0 : 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] == 1) dp[i] = dp[i - 1] + 1; 
        }
        return *max_element(dp.begin(), dp.end());
    }
};
