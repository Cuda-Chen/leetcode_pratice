// https://zxi.mytechroad.com/blog/heap/leetcode-239-sliding-window-maximum/
// monotonice queue (only recording index)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> index;
        
        for(int i = 0; i < n; i++) {
            while(!index.empty() && nums[i] >= nums[index.back()])
                index.pop_back();
            index.push_back(i);
            if(i - k + 1 >= 0) ans.push_back(nums[index.front()]);
            if(i - k + 1 >= index.front()) index.pop_front();
        }
        
        return ans;
    }
};
