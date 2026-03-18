class Solution {
public:
    int countSubmatrices(vector<vector<int>>& g, int k) {
        int m = g.size();
        int n = g[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0)
                    continue;
                else if(i == 0)
                    g[i][j] += g[i][j - 1];
                else if(j == 0)
                    g[i][j] += g[i - 1][j];
                else
                    g[i][j] += (g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1]);
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                ans += (g[i][j] <= k);
        }
        return ans;
    }
};
