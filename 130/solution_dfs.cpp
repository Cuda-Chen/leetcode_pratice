// https://zxi.mytechroad.com/blog/searching/leetcode-130-surrounded-regions/
// DFS
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        
        function<void(int, int)> dfs = [&](int i, int j) {
            if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') return;
            board[i][j] = 'G';
            vector<int> d{-1, 0, 1, 0, -1};
            for(int k = 0; k < 4; k++)
                dfs(i + d[k], j + d[k + 1]);
        };
        
        for(int i = 0; i < m; i++) {
            dfs(i, 0), dfs(i, n - 1);
        }
        for(int j = 0; j < n; j++) {
            dfs(0, j), dfs(m - 1, j);
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                board[i][j] = board[i][j] == 'G' ? 'O' : 'X';
        }
    }
};
