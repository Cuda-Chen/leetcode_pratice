// DFS + memorization

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int result = 0;
        if(matrix.empty()) {
            return result;
        }
        _n = matrix.size(), _m = matrix[0].size();
        _dp = vector<vector<int>>(_n, vector<int>(_m, -1));
        
        for(int i = 0; i < _n; i++) {
            for(int j = 0; j < _m; j++) {
                result = max(result, DFS(matrix, i, j));
            }
        }
        
        return result;
    }
    
private:
    int DFS(vector<vector<int>>& matrix, int i, int j) {
        if(_dp[i][j] != -1) {
            return _dp[i][j];
        }
        
        _dp[i][j] = 1;
        static int dirs[] = {0, 1, 0, -1, 0};
        for(int k = 0; k < 4; k++) {
            int x = i + dirs[k];
            int y = j + dirs[k + 1];
            if(x < 0 || y < 0 || x >= _n || y >= _m || matrix[x][y] <= matrix[i][j]) {
                continue;
            }
            _dp[i][j] = max(_dp[i][j], 1 + DFS(matrix, x, y));
        }
        
        return _dp[i][j];
    }
    
    int _n, _m;
    vector<vector<int>> _dp; //_dp[i][j]: maximum path on [i, j]
};
