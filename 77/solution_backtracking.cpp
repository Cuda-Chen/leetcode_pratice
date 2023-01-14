// backtracking

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        function<void(int)> dfs = [&](int s) {
            if(cur.size() == k) {
                ans.push_back(cur);
                return;
            }
            for(int i = s; i < n; i++) {
                cur.push_back(i + 1);
                dfs(i + 1);
                cur.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
