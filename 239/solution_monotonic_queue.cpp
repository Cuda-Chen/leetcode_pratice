// https://zxi.mytechroad.com/blog/heap/leetcode-239-sliding-window-maximum/
// monotonic queue

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> q;
        
        for(int i = 0; i < n; i++) {
            while(!q.empty() && nums[i] > q.back()) q.pop_back();
            q.push_back(nums[i]);
            if(i - k + 1 >= 0) {
                ans.push_back(q.front());
                if(nums[i - k + 1] >= q.front()) q.pop_front();
            }
        }
        
        return ans;
    }
};
