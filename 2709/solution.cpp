// https://walkccc.me/LeetCode/problems/2709/
// Disjoint set

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

    int getSize(int u) {
        return sz[u];
    }

private:
    vector<int> id;
    vector<int> sz;
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& A) {
        int n = A.size();
        unordered_map<int, int> m; // {prime, first idx}
        int mx = ranges::max(A);
        vector<int> primes = s(mx + 1);
        UnionFind uf(n);
        for(int i = 0; i < n; i++) {
            for(int p : getPrimeFactors(A[i], primes)) {
                if(m.count(p))
                    uf.unionBySize(m[p], i);
                else
                    m[p] = i;
            }
        }

        for(int i = 0; i < n; i++) {
            if(uf.getSize(i) == n)
                return true;
        }
        return false;
    }

private:
    // Gets the minimum prime factor of i, where 1 < i <= n.
    // sieveEratosthenes
    vector<int> s(int n) {
        vector<int> ret(n + 1);
        iota(begin(ret) + 2, end(ret), 2);
        for(int i = 2; i * i <= n; i++) {
            if(ret[i] == i) { // if `i` is prime
                for(int j = i * i; j < n; j += i)
                    ret[j] = min(ret[j], i);
            }
        }
        return ret;
    }

    vector<int> getPrimeFactors(int n, vector<int> &p) {
        vector<int> ret;
        while(n > 1) {
            int d = p[n];
            ret.push_back(d);
            while(n % d == 0)
                n /= d;
        }
        return ret;
    }
};
