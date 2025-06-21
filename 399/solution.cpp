// https://walkccc.me/LeetCode/problems/399/
// shortest path

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> g;
        for(int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            g[u][v] = val;
            g[v][u] = 1.0 / val;
        }

        vector<double> ans;
        for(auto &q : queries) {
            string u = q[0];
            string v = q[1];
            unordered_set<string> seen;
            if(!g.count(u) || !g.count(v))
                ans.push_back(-1.0);
            else
                ans.push_back(dfs(g, u, v, seen));
        }
        return ans;
    }

private:
    double dfs(
        unordered_map<string, unordered_map<string, double>> &g,
        const string &src,
        const string &dst,
        unordered_set<string> &seen
    ) {
        if(src == dst)
            return 1.0;

        seen.insert(src);
        for(auto &[v, w] : g[src]) {
            if(seen.count(v))
                continue;
            
            double tmp = dfs(g, v, dst, seen);
            if(tmp > 0)
                return w * tmp;
        }
        return -1.0;
    }
};
