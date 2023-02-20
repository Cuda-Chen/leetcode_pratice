// DFS

class Solution {
public:
    int numEnclaves(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        int ans = 0;
        vector<int> d{0, 1, 0, -1, 0};
        function<bool(int, int, int &)> dfs = [&](int i, int j, int &cnt) {
            if(i < 0 || j < 0 || i >= n || j >= m)
                return true;
            if(g[i][j] == 0)
                return false;
            g[i][j] = 0;
            cnt++;
            bool flag = false;
            for(int k = 0; k < 4; k++)
                flag |= dfs(i + d[k], j + d[k + 1], cnt);
            return flag;
        };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int cnt = 0;
                if(!dfs(i, j, cnt))
                    ans += cnt;
            }
        }
        return ans;
    }
};
