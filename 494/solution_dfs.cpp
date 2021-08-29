// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-494-target-sum/
// DFS
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        S = abs(S);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < S) return 0;
        int ans = 0;
        dfs(nums, 0, S, ans);
        return ans;
    }
    
private:
    void dfs(vector<int> &nums, int d, int target, int &ans) {
        if(d == nums.size()) {
            if(target == 0) ans++;
            return;
        }
        dfs(nums, d + 1, target - nums[d], ans);
        dfs(nums, d + 1, target + nums[d], ans);
    }
};
