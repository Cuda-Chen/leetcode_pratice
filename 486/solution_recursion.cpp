// https://zxi.mytechroad.com/blog/leetcode/leetcode-486-predict-the-winner/
// recursive

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return getScore(nums, 0, n - 1) >= 0;
    }
    
private:
    int getScore(vector<int> &nums, int l, int r) {
        if(l == r) return nums[l];
        return max(nums[l] - getScore(nums, l + 1, r),
                   nums[r] - getScore(nums, l, r - 1));
    }
};
