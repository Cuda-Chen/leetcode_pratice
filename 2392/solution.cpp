class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> r = topo(rowConditions, k);
        vector<int> c = topo(colConditions, k);
        if(r.empty() || c.empty())
            return {};
        
        vector<int> m(k + 1);
        for(int i = 0; i < k; i++)
            m[r[i]] = i;
        vector<vector<int>> ans(k, vector<int>(k));
        for(int j = 0; j < k; j++) {
            int node = c[j];
            int i = m[node];
            ans[i][j] = node;
        }
        return ans;
    }

private:
    vector<int> topo(vector<vector<int>> &edges, int n) {
        vector<vector<int>> g(n + 1, vector<int>(n + 1));
        vector<int> in(n + 1);
        for(auto e : edges) {
            int u = e[0];
            int v = e[1];
            g[u].push_back(v);
            in[v]++;
        }

        queue<int> q;
        for(int i = 1; i <= n; i++) {
            if(in[i] == 0)
                q.push(i);
        }

        vector<int> ret;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ret.push_back(u);
            for(int v : g[u]) {
                if(--in[v] == 0)
                    q.push(v);
            }
        }

        return ret.size() == n
            ? ret
            : vector<int>();
    }
};
