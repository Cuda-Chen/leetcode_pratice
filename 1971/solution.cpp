class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        if(n == 1)
            return true;
        if(src == dst)
            return true;

        unordered_map<int, unordered_set<int>> g;
        for(auto e : edges) {
            int u = e[0], v = e[1];
            if(!g.count(u))
                g[u] = {};
            if(!g.count(v))
                g[v] = {};
            g[u].insert(v);
            g[v].insert(u);
       }
       
       queue<int> q;
       unordered_set<int> seen;
       if(!g.count(src))
            return false;
        q.push(src);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(u == dst)
                return true;
            if(seen.count(u))
                continue;
            seen.insert(u);
            for(int v : g[u])
                q.push(v);
        }
       return false;
    }
};
