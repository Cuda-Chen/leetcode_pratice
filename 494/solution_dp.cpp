// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-494-target-sum/
// DP (bottom-up)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        S = abs(S);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < S) return 0;
        int offset = sum;
        int n = nums.size();
        vector<vector<int>> ways(n + 1, vector<int>(sum + offset + 1, 0));
        ways[0][offset] = 1;
        
        for(int i = 0; i < n; i++) {
            for(int j = nums[i]; j < 2 * sum + 1 - nums[i]; j++) {
                if(ways[i][j]) {
                    ways[i + 1][j - nums[i]] += ways[i][j];
                    ways[i + 1][j + nums[i]] += ways[i][j]; 
                }
            }
        }
        
        return ways.back()[S + offset];
    }
};
