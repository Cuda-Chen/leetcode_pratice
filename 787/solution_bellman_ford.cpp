// Bellman-Ford

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
        dist[src][0] = 0;
        for(int i = 1; i <= k + 1; i++) {
            dist[src][i] = 0;
            for(int u = 0; u < n; u++) {
                for(auto &[v, w] : g[u]) {
                    if(dist[v][i] > dist[u][i - 1] + w)
                        dist[v][i] = dist[u][i - 1] + w;
                }
            }
        }
        return dist[dst][k + 1] == kmax
            ? -1
            : dist[dst][k + 1];
    }
};
