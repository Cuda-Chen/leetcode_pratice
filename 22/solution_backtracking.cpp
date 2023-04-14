// backtracking

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        function<void(int, int)> dfs = [&](int l, int r) {
            if(l == 0 && r == 0) {
                ans.push_back(cur);
                return;
            }
            if(l < 0 || r < 0 || r < l)
                return;

            cur.push_back('(');
            dfs(l - 1, r);
            cur.pop_back();

            cur.push_back(')');
            dfs(l, r - 1);
            cur.pop_back();
        };
        dfs(n, n);
        return ans;
    }
};
