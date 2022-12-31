// backtracking

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        int n = nums.size();
        vector<int> used(n);
        function<void(int)> dfs = [&](int s) {
            if(s == n) {
                ans.push_back(cur);
                return;
            }
            for(int i = 0; i < n; i++) {
                if(used[i])
                    continue;
                cur.push_back(nums[i]);
                used[i] = 1;
                dfs(s + 1);
                used[i] = 0;
                cur.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
