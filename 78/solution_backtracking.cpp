// backtracking

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        function<void(int, int)> dfs = [&](int n, int s) {
            if(cur.size() == n) {
                ans.push_back(cur);
                return;
            }
            for(int i = s; i < nums.size(); i++) {
                cur.push_back(nums[i]);
                dfs(n, i + 1);
                cur.pop_back();
            }
        };
        for(int i = 0; i <= nums.size(); i++)
            dfs(i, 0);
        return ans;
    }
};
