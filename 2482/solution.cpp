class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        vector<int> r_o(m), r_z(m);
        vector<int> c_o(n), c_z(n);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(g[i][j] == 1)
                    r_o[i]++;
                else
                    r_z[i]++;
            }
        }
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) {
                if(g[i][j] == 1)
                    c_o[j]++;
                else
                    c_z[j]++;
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans[i][j] = 
                    r_o[i] +
                    c_o[j] -
                    r_z[i] -
                    c_z[j];
            }
        }
        return ans;
    }
};
