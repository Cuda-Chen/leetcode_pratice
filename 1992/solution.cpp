class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(g[i][j] == 0)
                    continue;

                int r = i, c = j;
                dfs(g, i, j, r, c);
                ans.push_back({i, j, r, c});
            }
        }
        return ans;
    }

private:
    vector<int> d{0, 1, 0, -1, 0};

    void dfs(
        vector<vector<int>> &g,
        int i,
        int j,
        int &r,
        int &c
    ) {
        if(i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == 0)
            return;

        g[i][j] = 0;
        r = max(r, i);
        c = max(c, j);
        for(int k = 0; k < 4; k++)
            dfs(g, i + d[k], j + d[k + 1], r, c);
    }
};
