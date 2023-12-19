class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        vector<pair<int, int>> dirs{
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0, -1},
            {0, 0},
            {0, 1},
            {1, -1},
            {1, 0},
            {1, 1}
        };
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int cnt = 0;
                int sum = 0;
                for(auto d : dirs) {
                    int y = d.first;
                    int x = d.second;
                    int ii = i + y;
                    int jj = j + x;
                    if(ii < 0 || jj < 0 || ii >= m || jj >= n)
                        continue;
                    cnt++;
                    sum += img[ii][jj];
                }
                ans[i][j] = sum / cnt;
            }
        }
        return ans;
    }
};
