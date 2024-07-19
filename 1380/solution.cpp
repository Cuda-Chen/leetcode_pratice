class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // Get the min of each row
        vector<vector<int>> tmp; // {num, col idx}
        for(int i = 0; i < m; i++) {
            auto it = min_element(mat[i].begin(), mat[i].end());
            int idx = it - mat[i].begin();
            tmp.push_back({*it, idx});
        }

        vector<int> ans;
        for(auto t : tmp) {
            int num = t[0];
            int idx = t[1];

            vector<int> col(m);
            for(int i = 0; i < m; i++)
                col[i] = mat[i][idx];
            int tt = ranges::max(col);
            if(num == tt)
                ans.push_back(num);
        }
        return ans;
    }
};
