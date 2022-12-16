// backtracking

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
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
            if(c[i] > target)
                break;
            cur.push_back(c[i]);
            dfs(c, target - c[i], i, cur, ans);
            cur.pop_back();
        }
    }
};
