class Solution {
public:
    vector<int> frequencySort(vector<int>& A) {
        unordered_map<int, int> m; // {num, freq}
        for(int a : A)
            m[a]++;

        vector<pair<int, int>> v;
        for(auto [k, val] : m)
            v.push_back({k, val});

        ranges::sort(v, [](const auto &a, const auto &b) {
            if(a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        });

        vector<int> ans;
        for(auto [e, _] : v) {
            for(int i = 0; i < m[e]; i++)
                ans.push_back(e);
        }
        return ans;
    }
};
