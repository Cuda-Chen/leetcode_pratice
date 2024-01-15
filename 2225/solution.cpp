class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        unordered_map<int, int> m; // {matcher, lost count}
        for(auto mm : matches) {
            int w = mm[0];
            int l = mm[1];
            if(!m.count(w))
                m[w] = 0;
            m[l]++;
        }

        for(auto &[matcher, lc] : m) {
            if(lc == 0)
                ans[0].push_back(matcher);
            else if(lc == 1)
                ans[1].push_back(matcher);
        }
        ranges::sort(ans[0]);
        ranges::sort(ans[1]);
        return ans;
    }
};
