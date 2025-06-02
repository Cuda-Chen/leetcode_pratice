// Disjoint set

class UnionFind {
public:
    UnionFind(int n) : id(n), rank(n) {
        iota(begin(id), end(id), 0);
    }

    void unionByRank(int u, int v) {
        link(find(u), find(v));
    }

    void link(int i, int j) {
        if(rank[i] > rank[j]) {
            id[j] = i;
        } else {
            id[i] = j;
            if(rank[i] == rank[j])
                rank[j]++;
        }
    }

    int find(int u) {
        return u == id[u]
            ? u
            : id[u] = find(id[u]);
    }

private:
    vector<int> id;
    vector<int> rank;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1; // the node number start from 1.
        UnionFind uf(n);
        vector<int> ans(2);
        for(auto e : edges) {
            int u = e[0];
            int v = e[1];
            int i = uf.find(u);
            int j = uf.find(v);
            if(uf.find(u) == uf.find(v)) {
                ans[0] = u;
                ans[1] = v;
                continue;
            }
            uf.unionByRank(u, v);
        }
        return ans;
    }
};
