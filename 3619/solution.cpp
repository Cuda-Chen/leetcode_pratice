class Solution {
public:
    int countIslands(vector<vector<int>>& g, int k) {
        int m = g.size();
        int n = g[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(g[i][j] == 0)
                    continue;

                long sum = 0;
                dfs(g, i, j, sum);
                if(sum % k == 0)
                    ans++;
            }
        }
        return ans;
    }

private:
    vector<int> d{0, 1, 0, -1, 0};

    void dfs(vector<vector<int>> &g, int i, int j, long &sum) {
        if(i < 0 || j < 0 || i >= g.size() || j >= g[0].size())
            return;
        if(g[i][j] == 0)
            return;

        sum += g[i][j];
        g[i][j] = 0;
        for(int k = 0; k < 4; k++)
            dfs(g, i + d[k], j + d[k + 1], sum);
    }
};
