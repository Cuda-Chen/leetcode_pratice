// DFS

class Solution {
public:
    int closedIsland(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        int ans = 0;
        vector<int> d{0, 1, 0, -1, 0};
        function<int(int, int)> dfs = [&](int i, int j) {
            if(i < 0 || j < 0 || i >= n || j >= m)
                return 0;
            if(g[i][j]++)
                return 1;
            int ret = 1;
            for(int k = 0; k < 4; k++)
                ret &= dfs(i + d[k], j + d[k + 1]);
            return ret;
        };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!g[i][j])
                    ans += dfs(i, j);
            }
        }
        return ans;
    }
};
