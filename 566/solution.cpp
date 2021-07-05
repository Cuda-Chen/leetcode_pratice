// naive, just indexing

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans(r, vector<int>(c));
        int n = mat.size(), m = mat[0].size();

        // If output shape is not valid
        if(n * m != r * c) return mat; 
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int idx = i * m + j;
                int a = idx / c;
                int b = idx % c;
                
                ans[a][b] = mat[i][j];
            }
        }
        
        return ans;
    }
};
