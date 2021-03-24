// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-221-maximal-square/
// DP

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        // sums[i][j] = sum(matrix[0][0] ~ matrix[i-1][j-1])
        vector<vector<int>> sums(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                sums[i][j] = matrix[i - 1][j - 1] - '0'
                    + sums[i - 1][j]
                    + sums[i][j - 1]
                    - sums[i - 1][j - 1];
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                for(int k = min(m - i + 1, n - j + 1); k > 0; k--) {
                    int sum = sums[i + k - 1][j + k - 1]
                        - sums[i - 1][j + k - 1]
                        - sums[i + k - 1][j - 1]
                        + sums[i - 1][j - 1];
                    if(sum == k * k) {
                        ans = max(ans, sum);
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};
