// https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-2/unionfind-suan-fa-ying-yong#er-pan-ding-he-fa-deng-shi
// union-find

class UF {
public:
    UF(int n) : count(n), parent(n), size(n) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    void unite(int p, int q) {
        int rootP = find(p), rootQ = find(q);
        if(rootP == rootQ) return;
        
        if(size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        count--;
    }
    
    bool connected(int p, int q) {
        int rootP = find(p), rootQ = find(q);
        return (rootP == rootQ);
    }
    
private:
    int count;
    vector<int> parent, size;
    
    int find(int x) {
        while(parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UF uf(26);
        for(string eq : equations) {
            if(eq[1] == '=') {
                char x = eq[0];
                char y = eq[3];
                uf.unite(x - 'a', y - 'a');
            }
        }
        
        for(string eq : equations) {
            if(eq[1] == '!') {
                char x = eq[0];
                char y = eq[3];
                if(uf.connected(x - 'a', y - 'a'))
                    return false;
            }
        }
        
        return true;
    }
};
