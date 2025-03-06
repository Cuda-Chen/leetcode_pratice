class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> cnt(n * n + 1);
        for(auto v : g) {
            for(int e : v)
                cnt[e]++;
        }

        vector<int> ans(2);
        for(int i = 1; i <= n * n; i++) {
            if(cnt[i] == 2)
                ans[0] = i;
            else if(cnt[i] == 0)
                ans[1] = i;
        }
        return ans;
    }
};
