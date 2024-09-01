class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m * n != original.size())
            return {};

        vector<vector<int>> ans(m, vector<int>(n));
        int idx = 0;
        while(idx < m * n) {
            int i = idx / n;
            int j = idx % n;
            ans[i][j] = original[idx];
            idx++;
        }
        return ans;
    }
};
