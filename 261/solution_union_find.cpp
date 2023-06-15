// https://walkccc.me/LeetCode/problems/0261/
// union-find

class UnionFind {
public:
    UnionFind(int n) : cnt(n), id(n), rank(n) {
        iota(id.begin(), id.end(), 0);
    }

    void unionByRank(int u, int v) {
        int i = find(u);
        int j = find(v);
        if(i == j)
            return;
        if(rank[i] < rank[j])
            id[i] = id[j];
        else if(rank[i] > rank[j])
            id[j] = id[i];
        else {
            id[i] = id[j];
            ++rank[j];
        }
        --cnt;
    }

    int getCount() const {
        return cnt;
    }

private:
    int cnt;
    vector<int> id, rank;

    int find(int u) {
        return id[u] == u
            ? u
            : id[u] = find(id[u]);
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n == 0 || edges.size() != n - 1)
            return false;

        UnionFind uf(n);

        for(auto e : edges)
            uf.unionByRank(e[0], e[1]);

        return uf.getCount() == 1;
    }
};
