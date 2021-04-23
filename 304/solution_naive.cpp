// naive (TLE)

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        vector<int> temp;
        for(const auto &arr : matrix) {
            temp = vector<int>(arr);
            mat.push_back(temp);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = 0;
        for(int i = row1; i <= row2; i++) {
            for(int j = col1; j <= col2; j++) {
                result += mat[i][j];
            }
        }
        return result;
    }
    
private:
    vector<vector<int>> mat;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
