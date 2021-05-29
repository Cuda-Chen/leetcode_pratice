// https://zxi.mytechroad.com/blog/searching/leetcode-51-n-queens/
// backtracking

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        cols = vector<int>(n, 0);
        diag1 = vector<int>(2 * n + 1, 0);
        diag2 = vector<int>(2 * n + 1, 0);
        
        nqueens(n, 0);
        
        return result;
    }
    
private:
    vector<vector<string>> result;
    vector<string> board;
    vector<int> cols, diag1, diag2;
    
    bool available(int x, int y, int n) {
        return !cols[x] &&
            !diag1[x + y] &&
            !diag2[x - y + n - 1];
    }
    
    void updateBoard(int x, int y, int n, bool flag) {
        cols[x] = diag1[x + y] = diag2[x - y + n - 1] = flag;
        board[y][x] = flag ? 'Q' : '.';
    }
    
    void nqueens(int n, int y) {
        if(y == n) {
            result.push_back(board);
            return;
        }
        
        for(int x = 0; x < n; x++) {
            if(!available(x, y, n)) continue;
            updateBoard(x, y, n, true);
            nqueens(n, y + 1);
            updateBoard(x, y, n, false);
        }
    }
};
