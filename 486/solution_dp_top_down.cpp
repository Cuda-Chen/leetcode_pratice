// https://zxi.mytechroad.com/blog/leetcode/leetcode-486-predict-the-winner/
// DP (top-down)

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp = vector<vector<int>>(n, vector<int>(n, INT_MIN));
        return getScore(nums, 0, n - 1) >= 0;
    }
    
private:
    vector<vector<int>> dp;
    
    int getScore(vector<int> &nums, int l, int r) {
        if(l == r) return dp[l][r] = nums[l];
        if(dp[l][r] != INT_MIN) return dp[l][r];
        
        dp[l][r] = max(nums[l] - getScore(nums, l + 1, r),
                       nums[r] - getScore(nums, l, r - 1));
        return dp[l][r];
    }
};
