class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& g, int x, int y, int k) {
        vector<vector<int>> ans(g);
        for(int j = y; j < y + k; j++) {
            for(int i = 0; i < k / 2; i++) {
                int tmp = ans[x + i][j];
                ans[x + i][j] = ans[x + (k - i - 1)][j];
                ans[x + (k - i - 1)][j] = tmp;
            }
        }
        return ans;
    }
};
