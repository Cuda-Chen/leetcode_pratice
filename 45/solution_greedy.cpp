// greedy

class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int near = 0, far = 0;
        for(int i = 0; i < n; i++) {
            if(i > near) {
                ans++;
                near = far;
            }
            far = max(far, i + nums[i]);
        }
        return ans;
    }
};
