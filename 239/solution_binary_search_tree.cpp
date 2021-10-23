// https://zxi.mytechroad.com/blog/heap/leetcode-239-sliding-window-maximum/
// binary search tree (C++ multiset)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        multiset<int> window(nums.begin(), nums.begin() + k - 1);
        
        for(int i = k - 1; i < n; i++) {
            window.insert(nums[i]);
            ans.push_back(*window.rbegin());
            if(i - k + 1 >= 0)
                window.erase(window.equal_range(nums[i - k + 1]).first);
        }
        
        return ans;
    }
};
