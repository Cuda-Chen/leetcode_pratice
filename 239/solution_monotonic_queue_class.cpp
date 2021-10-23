// https://zxi.mytechroad.com/blog/heap/leetcode-239-sliding-window-maximum/
// monotonice queue (w/ class)

class MonotonicQueue {
public:
    void push(int e) {
        while(!q.empty() && e > q.back()) q.pop_back();
        q.push_back(e);
    }
    
    void pop() { q.pop_front(); }
    
    int max() const { return q.front(); }
    
private:
    deque<int> q;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        MonotonicQueue q;
        
        for(int i = 0; i < n; i++) {
            q.push(nums[i]);
            if(i - k + 1 >= 0) {
                ans.push_back(q.max());
                if(nums[i - k + 1] == q.max()) q.pop();
            }
        }
        
        return ans;
    }
};
