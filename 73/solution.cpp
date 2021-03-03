// naive

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>> zeros;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0)
                    zeros.push_back({i, j});
            }
        }
        
        for(auto &elem : zeros) {
            for(int i = 0; i < m; i++)
                matrix[i][elem.second] = 0;
            for(int j = 0; j < n; j++)
                matrix[elem.first][j] = 0;
        }
    }
};
