// https://walkccc.me/LeetCode/problems/310/
// topological sort
// start from leaf, then go to the center -> topological sort

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1 || edges.empty())
            return {0};

        unordered_map<int, unordered_set<int>> g;
        for(auto e : edges) {
            int u = e[0];
            int v = e[1];
            g[u].insert(v);
            g[v].insert(u);
        }

        vector<int> ans;
        for(auto &[u, children] : g) {
            if(children.size() == 1)
                ans.push_back(u);
        }
        while(n > 2) {
            n -= ans.size();
            vector<int> tmp;
            for(int leaf : ans) {
                int u = *g[leaf].begin();
                g[u].erase(leaf);
                if(g[u].size() == 1)
                    tmp.push_back(u);
            }
            ans = tmp;
        }
        return ans;
    }
};
