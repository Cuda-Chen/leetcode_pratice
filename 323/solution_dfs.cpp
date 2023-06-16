// https://walkccc.me/LeetCode/problems/0323/
// DFS

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
                dfs(g, i, seen);
                ans++;
            }
        }

        return ans;
    }

private:
    void dfs(vector<vector<int>> &g, int src, unordered_set<int> &seen) {
        for(int v : g[src]) {
            if(seen.insert(v).second)
                dfs(g, v, seen);
        }
    }
};
