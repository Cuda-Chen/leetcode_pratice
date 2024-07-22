class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>> p;
        int n = names.size();
        for(int i = 0; i < n; i++)
            p.push_back({names[i], heights[i]});

        ranges::sort(p, [](const auto &a, const auto &b) {
            return a.second > b.second;
        });

        vector<string> ans;
        for(auto e : p)
            ans.push_back(e.first);
        return ans;
    }
};
