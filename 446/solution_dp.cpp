// https://www.cnblogs.com/grandyang/p/6057934.html
// DP + hash table
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), result = 0;
        vector<unordered_map<int, int>> dp(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                long delta = (long) nums[i] - nums[j];
                if(delta > INT_MAX || delta < INT_MIN) continue;
                int diff = (int) delta;
                ++dp[i][diff];
                if(dp[j].count(diff)) {
                    result += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
            }
        }
        
        return result;
    }
};
