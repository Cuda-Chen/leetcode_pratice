// backtracking

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(begin(nums), end(nums));
        function<void(int)> dfs = [&](int s) {
            ans.push_back(cur);
            if(cur.size() == nums.size())
                return;
            for(int i = s; i < nums.size(); i++) {
                if(i > s && nums[i] == nums[i - 1])
                    continue;
                cur.push_back(nums[i]);
                dfs(i + 1);
                cur.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
