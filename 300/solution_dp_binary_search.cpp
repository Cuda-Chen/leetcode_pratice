// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-300-longest-increasing-subsequence/
// DP + binary search

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        for(int i = 0; i < n; i++) {
            auto it = lower_bound(begin(dp), end(dp), nums[i]);
            if(it == end(dp))
                dp.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return dp.size();
    }
};
