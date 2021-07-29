// https://zxi.mytechroad.com/blog/math/leetcode-396-rotate-function/
// DP

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, f = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            f += i * nums[i];
        }
        
        int ans = f;
        for(int i = 0; i < n - 1; i++) {
            f = f + sum - n * nums[n - i - 1];
            ans = max(ans, f);
        }
        
        return ans;
    }
};
