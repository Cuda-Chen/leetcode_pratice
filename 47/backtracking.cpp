// backtracking

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;
        vector<int> used(nums.size()), cur;
        dfs(nums, cur, used, ans);
        return ans;
    }

private:
    void dfs(vector<int> &nums, vector<int> &cur, vector<int> &used, vector<vector<int>> &ans) {
        if(cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(used[i])
                continue;
            if(i > 0 && nums[i - 1] == nums[i] && !used[i - 1])
                continue;
            used[i] = 1;
            cur.push_back(nums[i]);
            dfs(nums, cur, used, ans);
            cur.pop_back();
            used[i] = 0;
        }
    }
};
