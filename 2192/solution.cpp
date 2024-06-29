class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> g; // a reverse graph
        for(auto e : edges) {
            int u = e[0];
            int v = e[1];
            if(!g.count(v))
                g[v] = {};
            g[v].insert(u);
        }

        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            vector<int> l;
            bfs(g, i, l);
            ranges::sort(l);
            ans.push_back(l);
        }
        return ans;
    }

private:
    void bfs(
        unordered_map<int, unordered_set<int>> &g,
        int v,
        vector<int> &tmp
    ) {
        queue<int> q;
        unordered_set<int> seen;
        for(int u : g[v])
            q.push(u);
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            if(seen.count(t))
                continue;
            tmp.push_back(t);
            seen.insert(t);
            for(int tt : g[t])
                q.push(tt);
        }
    }
};
