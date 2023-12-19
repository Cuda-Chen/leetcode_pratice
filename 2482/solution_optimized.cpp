// Use two arrays to count the 1's of each row and column.

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        vector<int> r_o(m);
        vector<int> c_o(n);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(g[i][j] == 1)
                    r_o[i]++;
            }
        }
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) {
                if(g[i][j] == 1)
                    c_o[j]++;
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans[i][j] = 
                    r_o[i] * 2 +
                    c_o[j] * 2 -
                    m -
                    n;
            }
        }
        return ans;
    }
};
