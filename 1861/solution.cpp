class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                ans[i][j] = box[m - 1 - j][i];
        }

        for(int j = 0; j < m; j++) {
            int t, b;
            b = t = n;
            int cnt = 0;
            while(b >= 0) {
                t--;
                if(t < 0 || ans[t][j] == '*') {
                    for(int i = b - 1; i > t; i--) {
                        ans[i][j] = cnt > 0 ? '#' : '.';
                        if(cnt > 0)
                            cnt--;
                    }
                    b = t;
                } else if(ans[t][j] == '#')
                    cnt++;
            }
        }

        return ans;
    }
};
