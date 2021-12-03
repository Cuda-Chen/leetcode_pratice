// https://zxi.mytechroad.com/blog/dynamic-programming/688-knight-probability-in-chessboard/
// DP (bottom-up)

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp0(N, vector<double>(N, 0));
        dp0[r][c] = 1;
        int dirs[8][2] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2},
                          {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
        for(int k = 0; k < K; k++) {
            vector<vector<double>> dp1(N, vector<double>(N, 0));
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++)
                    for(int m = 0; m < 8; m++) {
                        int x = i + dirs[m][0];
                        int y = j + dirs[m][1];
                        if(x < 0 || x >= N || y < 0 || y >= N) continue;
                        dp1[i][j] += dp0[x][y];
                    }
            std::swap(dp0, dp1);
        }
        
        double total = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                total += dp0[i][j];
        return total / pow(8, K);
    }
};
