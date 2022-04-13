// simulation

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int cnt = 1;
        int d = 0, y = 0, x = 0;
        int l = 0, r = n, t = 0, b = n;
        int total = (r--) * (b--);

        while(cnt < total) {
            if(d == 0) {
                while(x < r) {
                    ans[y][x++] = cnt++;
                }
                t++;
            } else if(d == 1) {
                while(y < b) {
                    ans[y++][x] = cnt++;
                }
                r--;
            } else if(d == 2) {
                while(x > l) {
                    ans[y][x--] = cnt++;
                }
                b--;
            } else if(d == 3) {
                while(y > t) {
                    ans[y--][x] = cnt++;
                }
                l++;
            }
            d = (d + 1) % 4;
        }

        // Process the last element
        {
            if(d == 0)
                ans[y][x] = cnt;
            else if(d == 1)
                ans[y][x] = cnt;
            else if(d == 2)
                ans[y][x] = cnt;
            else if(d == 3)
                ans[y][x] = cnt;
        }

        return ans;
    }
};
