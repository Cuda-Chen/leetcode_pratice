// DP (bottom-up)

class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n = S.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        for(int len = 1; len <= n; len++) {
            for(int i = 0; i < n - len; i++) {
                const int j = i + len;
                if(S[i] == S[j]) {
                    int left = i + 1, right = j - 1;
                    dp[i][j] = dp[left][right] * 2;
                    while(left <= right && S[i] != S[left]) {
                        left++;
                    }
                    while(left <= right && S[i] != S[right]) {
                        right--;
                    }
                    
                    if(left == right) {
                        dp[i][j] += 1;
                    } else if(left > right) {
                        dp[i][j] += 2;
                    } else {
                        dp[i][j] -= dp[left + 1][right - 1];
                    }
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                }
                
                dp[i][j] = (dp[i][j] + kMod) % kMod;
            }
        }
        
        return dp[0][n - 1];
    }
    
private:
    static constexpr long kMod = 1000000007;
};
