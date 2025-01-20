class Solution {
public:
    int firstCompleteIndex(vector<int>& A, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rows(m);
        vector<int> cols(n);
        unordered_map<int, pair<int, int>> mm;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                mm[mat[i][j]] = {i, j};
        }

        for(int i = 0; i < A.size(); i++) {
            auto &[x, y] = mm[A[i]];
            rows[x]++;
            cols[y]++;
            if(rows[x] == n || cols[y] == m)
                return i;
        }
        throw;
    }
};
