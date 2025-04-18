// Dijkstra

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<vector<pair<int, int>>> g(n);
        for(auto e: edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            g[u].emplace_back(v, w);
        }

        int kmax = 1e9;
        vector<vector<int>> dist(n, vector<int>(k + 2, kmax));
        dist[src][k + 1] = 0;
        using T = tuple<int, int, int>; // {dist, u, stops}
        priority_queue<T, vector<T>, greater<T>> q;
        q.emplace(dist[src][k + 1], src, k + 1);
        while(!q.empty()) {
            auto [d, u, stops] = q.top();
            q.pop();
            if(u == dst)
                return d;
            if(stops == 0 || d > dist[u][stops])
                continue;
            for(auto &[v, w] : g[u]) {
                if(dist[v][stops - 1] > d + w) {
                    dist[v][stops - 1] = d + w;
                    q.emplace(dist[v][stops - 1], v, stops - 1);
                }
            }
        }
        return -1;
    }
};
