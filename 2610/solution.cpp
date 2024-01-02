class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& A) {
        unordered_map<int, int> m; // {num, cnt}
        for(int a : A)
            m[a]++;

        int mx = 0;
        for(auto kv : m)
            mx = max(mx, kv.second);

        vector<vector<int>> ans(mx);
        for(auto kv : m) {
            while(kv.second > 0) {
                ans[kv.second - 1].push_back(kv.first);
                kv.second--;
            }
        }
        return ans;
    }
};
