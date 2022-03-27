// sorting

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> tmp;
        for(int i = 0; i < mat.size(); i++) {
            tmp.push_back({accumulate(mat[i].begin(), mat[i].end(), 0), i});
        }
        sort(tmp.begin(), tmp.end(), [](const auto &a, const auto &b) {
            if(a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        });
        vector<int> ans;
        for(int i = 0; i < k; i++)
            ans.push_back(tmp[i].second);
        return ans;
    }
};
