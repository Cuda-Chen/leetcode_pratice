// graph + DFS

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& A) {
        int n = A.size();
        unordered_map<int, unordered_set<int>> g;
        unordered_map<int, int> m;
        for(auto a : A) {
            g[a[0]].insert(a[1]);
            g[a[1]].insert(a[0]);
            m[a[0]]++;
            m[a[1]]++;
        }
        
        int start;
        for(auto kv : m) {
            if(kv.second == 1) {
                start = kv.first;
                break;
            }
        }

        vector<int> ans;
        dfs(g, start, ans, m);
        return ans;
    }

private:
    void dfs(
        unordered_map<int, unordered_set<int>> &g,
        int u,
        vector<int> &ans,
        unordered_map<int, int> &m
    ) {
        if(m[u] <= 0)
            return;

        m[u] -= 2;
        ans.push_back(u);
        for(int v : g[u])
            dfs(g, v, ans, m);
    }
};
