// back tracking

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> used(n), path;
        function<void(int)> dfs = [&](int d) {
            if(d == n) {
                ans.push_back(path);
                return;
            }
            for(int i = 0; i < n; i++) {
                if(used[i])
                    continue;
                used[i] = 1;
                path.push_back(nums[i]);
                dfs(d + 1);
                path.pop_back();
                used[i] = 0;
            }
        };
        dfs(0);
        return ans;
    }
};
