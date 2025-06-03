// https://walkccc.me/LeetCode/problems/721/

class UnionFind {
public:
    UnionFind(int n) : id(n), sz(n, 1) {
        iota(begin(id), end(id), 0);
    }

    void unionBySize(int u, int v) {
        int i = find(u);
        int j = find(v);
        if(i == j)
            return;

        if(sz[i] > sz[j]) {
            sz[i] += sz[j];
            id[j] = i;
        } else {
            sz[j] += sz[i];
            id[i] = j;
        }
    }

    int find(int u) {
        while(u != id[u]) {
            u = id[u];
            id[u] = id[id[u]];
        }
        return u;
    }

private:
    vector<int> id;
    vector<int> sz;
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& A) {
        int n = A.size();
        unordered_map<string, int> m;
        unordered_map<int, set<string>> g;
        UnionFind uf(n);
        for(int i = 0; i < n; i++) {
            auto a = A[i];
            string name = a[0];
            for(int j = 1; j < a.size(); j++) {
                string email = a[j];
                if(!m.count(email))
                    m[email] = i;
                else
                    uf.unionBySize(i, m[email]);
            }
        }

        for(auto &[k, v] : m)
            g[uf.find(v)].insert(k);

        vector<vector<string>> ans;
        for(auto &[idx, emails] : g) {
            string name = A[idx][0];
            vector<string> tmp{name};
            tmp.insert(tmp.end(), emails.begin(), emails.end());
            ans.push_back(tmp);
        }
        return ans;
    }
};
