// https://walkccc.me/LeetCode/problems/1489/
// disjoint set

class UnionFind {
public:
    UnionFind(int n) : id(n), rank(n) {
        iota(begin(id), end(id), 0);
    }

    void unionByRank(int u, int v) {
        link(find(u), find(v));
    }

    void link(int u, int v) {
        if(rank[u] > rank[v]) {
            id[v] = u;
        } else {
            id[u] = v;
            if(rank[u] == rank[v])
                rank[v]++;
        }
    }

    int find(int u) {
        return u == id[u]
            ? u
            : id[u] = find(id[u]);
    }

private:
    vector<int> id, rank;
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < edges.size(); i++)
            edges[i].push_back(i);

        ranges::sort(edges, ranges::less{},
        [](const auto &e) { return e[2]; });

        int mst_w = getWeight(n, edges, {}, -1);
        vector<int> c, p;
        for(auto e : edges) {
            int idx = e[3];
            if(getWeight(n, edges, {}, idx) > mst_w)
                c.push_back(idx);
            else if(getWeight(n, edges, e, -1) == mst_w)
                p.push_back(idx);
        }
        return {c, p};
    }

private:
    int getWeight(int n, vector<vector<int>> &edges,
    const vector<int> &edge, int index) {
        UnionFind uf(n);
        int ret = 0;
        if(!edge.empty()) {
            uf.unionByRank(edge[0], edge[1]);
            ret += edge[2];
        }

        for(auto e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            int idx = e[3];
            if(idx == index)
                continue;
            if(uf.find(u) == uf.find(v))
                continue;
            uf.unionByRank(u, v);
            ret += w;
        }

        int root = uf.find(0);
        for(int i = 0; i < n; i++) {
            if(uf.find(i) != root)
                return INT_MAX;
        }
        return ret;
    }
};
