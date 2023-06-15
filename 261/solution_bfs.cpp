// https://walkccc.me/LeetCode/problems/0261/
// BFS

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n == 0 || edges.size() != n - 1)
            return false;
        
        vector<vector<int>> g(n);
        queue<int> q{{0}};
        unordered_set<int> seen{{0}};

        for(auto e : edges) {
            int u = e[0];
            int v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto v : g[u]) {
                if(!seen.count(v)) {
                    q.push(v);
                    seen.insert(v);
                }
            }
        }

        return seen.size() == n;
    }
};
