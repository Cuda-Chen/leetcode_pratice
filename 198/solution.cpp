// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-198-house-robber/
// DP (bottom-up)

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            dp[i] = max((i > 1 ? dp[i - 2] : 0) + nums[i],
                        (i > 0 ? dp[i - 1] : 0));
        }
        return dp[nums.size() - 1];
    }
};
