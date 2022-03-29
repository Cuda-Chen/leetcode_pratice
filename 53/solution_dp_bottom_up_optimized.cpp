// DP (bottom-up, optimized)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0, ans = INT_MIN;
        for(int num : nums) {
            cur = max(cur + num, num);
            ans = max(ans, cur);
        }
        return ans;
    }
};
