// https://walkccc.me/LeetCode/problems/0323/
// BFS

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>> g(n);
        unordered_set<int> seen;

        for(auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        for(int i = 0; i < n; i++) {
            if(!seen.count(i)) {
                bfs(g, i, seen);
                ans++;
            }
        }

        return ans;
    }

private:
    void bfs(vector<vector<int>> &g, int src, unordered_set<int> &seen) {
        queue<int> q{{src}};
        seen.insert(src);

        while(!q.empty()) {
            auto u = q.front();
            q.pop();
            for(int v : g[u]) {
                if(!seen.count(v)) {
                    q.push(v);
                    seen.insert(v);
                }
            }
        }
    }
};
