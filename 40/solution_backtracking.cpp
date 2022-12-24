// backtracking

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(c.begin(), c.end());
        dfs(c, target, 0, cur, ans);
        return ans;
    }

private:
    void dfs(vector<int> &c, int target, int s, vector<int> &cur, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(cur);
            return;
        }
        for(int i = s; i < c.size(); i++) {
            int num = c[i];
            if(num > target)
                return;
            if(i > s && num == c[i - 1])
                continue;
            cur.push_back(num);
            dfs(c, target - num, i + 1, cur, ans);
            cur.pop_back();
        }
    }
};
