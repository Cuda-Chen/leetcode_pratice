// DP

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size(), result = INT_MIN;
        vector<vector<int>> sums(m, vector<int>(n));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int temp = matrix[i][j];
                if(i > 0) temp += sums[i - 1][j];
                if(j > 0) temp += sums[i][j - 1];
                if(i > 0 && j > 0) temp -= sums[i - 1][j - 1];
                
                sums[i][j] = temp;
                
                for(int r = 0; r <= i; r++) {
                    for(int c = 0; c <= j; c++) {
                        int d = sums[i][j];
                        if(r > 0) d -= sums[r - 1][j];
                        if(c > 0) d -= sums[i][c - 1];
                        if(r > 0 && c > 0) d += sums[r - 1][c - 1];
                        
                        if(d <= k) result = max(result, d);
                    }
                }
            }
        }
        
        return result;
    }
};
