// sort then binary search

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        ranges::sort(items, [](const auto &a, const auto &b) {
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        vector<pair<int, int>> m; // {price, cur_max}
        m.push_back({items[0][0], items[0][1]});
        for(int i = 1; i < items.size(); i++) {
            if(items[i][0] == m.back().first) {
                m.back().second = max(m.back().second, items[i][1]);
                continue;
            }

            m.push_back({items[i][0], max(m.back().second, items[i][1])});
        }

        for(auto p : m)
            printf("%d %d\n", p.first, p.second);

        vector<int> ans;
        for(int query : queries) {
            auto it = upper_bound(m.begin(), m.end(), query, [](int value, const pair<int, int> &p) {
                return value < p.first;
            });
            int idx = it - m.begin() - 1;
            ans.push_back(idx < 0 ? 0 : m[idx].second);
        }
        return ans;
    }
};
