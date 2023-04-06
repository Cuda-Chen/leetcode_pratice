// backtracking

class Solution {
public:
    void solveSudoku(vector<vector<char>>& b) {
        vector<vector<int>> rows(9, vector<int>(10)),
            cols(9, vector<int>(10)),
            boxes(9, vector<int>(10));
        function<bool(int, int)> fill = [&](int x, int y) {
            if(y == 9)
                return true;
            int tx = (x + 1) % 9, ty = (tx == 0) ? y + 1 : y;
            if(b[y][x] != '.')
                return fill(tx, ty);
            for(int i = 1; i <= 9; i++) {
                int idx = (y / 3) * 3 + (x / 3);
                if(!rows[y][i] && !cols[x][i] && !boxes[idx][i]) {
                    rows[y][i] = cols[x][i] = boxes[idx][i] = 1;
                    b[y][x] = i + '0';
                    if(fill(tx, ty))
                        return true;
                    b[y][x] = '.';
                    rows[y][i] = cols[x][i] = boxes[idx][i] = 0;
                }
            }
            return false;
        };

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(b[i][j] != '.') {
                    int n = b[i][j] - '0';
                    rows[i][n] = cols[j][n] = boxes[(i / 3) * 3 + (j / 3)][n] = 1;
                }
            }
        }
        fill(0, 0);
    }
};
