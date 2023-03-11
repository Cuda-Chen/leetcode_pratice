// DFS

class Solution {
public:
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int n = g1.size(), m = g1[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!g1[i][j] && g2[i][j])
                    dfs(g2, i, j);
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(g2[i][j]) {
                    ans++;
                    dfs(g2, i, j);
                }
            }
        }
        return ans;
    }

private:
    vector<int> d{0, 1, 0, -1, 0};

    void dfs(vector<vector<int>> &g, int i, int j) {
        int n = g.size(), m = g[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m)
            return;
        if(!g[i][j])
            return;
        g[i][j] = 0;
        for(int k = 0; k < 4; k++)
            dfs(g, i + d[k], j + d[k + 1]);
    }
};
