class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& g) {
        vector<int> tmp(9);
        int n = g.size();
        vector<int> dir{-1, 0, 1};
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        int ii = 0, jj = 0;
        for(int i = 1; i <= n - 2; i++) {
            for(int j = 1; j <= n - 2; j++) {
                int idx = 0;
                for(int a: dir) {
                    for(int b : dir) {
                        tmp[idx] = g[i + a][j + b];
                        idx++;
                    }
                }

                ans[ii][jj] = *ranges::max_element(tmp);
                jj++;
            }
            ii++;
            jj = 0;
        }
        return ans;
    }
};
