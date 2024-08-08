class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int cnt = rows * cols - 1;
        int d = 0;
        int s = 1;
        vector<vector<int>> ans;
        int y = rStart, x = cStart;
        ans.push_back({y, x});
        while(cnt) {
            switch(d) {
                case 0:
                    for(int i = 0; i < s; i++) {
                        x++;
                        if(is_out(y, x, rows, cols))
                            continue;

                        cnt--;
                        ans.push_back({y, x});
                    }
                    break;
                case 1: // 1 -> 2
                    for(int i = 0; i < s; i++) {
                        y++;
                        if(is_out(y, x, rows, cols))
                            continue;

                        cnt--;
                        ans.push_back({y, x});
                    }

                    s++;
                    break;
                case 2:
                    for(int i = 0; i < s; i++) {
                        x--;
                        if(is_out(y, x, rows, cols))
                            continue;

                        cnt--;
                        ans.push_back({y, x});
                    }

                    break;
                case 3: // 2 -> 3
                    for(int i = 0; i < s; i++) {
                        y--;
                        if(is_out(y, x, rows, cols))
                            continue;

                        cnt--;
                        ans.push_back({y, x});
                    }

                    s++;
                    break;
            }
            d = (d + 1) % 4;
        }
        return ans;
    }

private:
    bool is_out(int y, int x, int r, int c) {
        return (y < 0) ||
            (y >= r) ||
            (x < 0) ||
            (x >= c);
    }
};
