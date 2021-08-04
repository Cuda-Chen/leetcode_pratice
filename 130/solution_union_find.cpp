// https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-2/unionfind-suan-fa-ying-yong#yi-dfs-de-ti-dai-fang-an
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
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int dummy = m * n;
        UF uf(dummy + 1);
        
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O')
                uf.unite(i * n, dummy);
            if(board[i][n - 1] == 'O')
                uf.unite(i * n + n - 1, dummy);
        }
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O')
                uf.unite(j, dummy);
            if(board[m - 1][j] == 'O')
                uf.unite((m - 1) * n + j, dummy);
        }
        
        for(int i = 1; i < m - 1; i++) {
            for(int j = 1; j < n - 1; j++) {
                if(board[i][j] == 'O') {
                    vector<int> d{-1, 0, 1, 0, -1};
                    for(int k = 0; k < 4; k++) {
                        int x = i + d[k];
                        int y = j + d[k + 1];
                        if(board[x][y] == 'O')
                            uf.unite(x * n + y, i * n + j);
                    }
                }
            }
        }
        
        for(int i = 1; i < m - 1; i++) {
            for(int j = 1; j < n - 1; j++) {
                if(!uf.connected(i * n + j, dummy))
                    board[i][j] = 'X';
            }
        }
    }
};
