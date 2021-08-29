// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-494-target-sum/
// subset sum
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        S = abs(S);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < S || (S + sum) % 2 != 0) return 0;
        int target = (S + sum) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            vector<int> temp(dp);
            for(int j = 0; j <= target - nums[i]; j++)
                temp[j + nums[i]] += dp[j];
            swap(dp, temp);
        }
        
        return dp[target];
    }
};
