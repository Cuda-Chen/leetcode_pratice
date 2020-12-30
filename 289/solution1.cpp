// naive (out-of-place)

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> result = vector<vector<int>>(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int count = 0;
                for(int k = 0; k < 8; k++) {
                    if(i + dx[k] >= 0 
                       && i + dx[k] < m
                       && j + dy[k] >= 0
                       && j + dy[k] < n
                       && board[i + dx[k]][j + dy[k]])
                        count++;
                }
                if(board[i][j]) { // live cell
                    if(count < 2 || count > 3)
                        result[i][j] = 0;
                    else if(count == 2 || count == 3)
                        result[i][j] = 1;
                } else { // dead cell
                    if(count == 3)
                        result[i][j] = 1;
                    else
                        result[i][j] = 0;
                }
            }
        }
        
        board = result;
    }
    
private:
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
};
