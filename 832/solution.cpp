// straightforward

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> result(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int temp = A[i][j];
                result[i][m - j - 1] = (temp == 0) ? 1 : 0;
            }
        }
        return result;
    }
};
