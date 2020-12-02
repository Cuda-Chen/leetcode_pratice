// http://web.ntnu.edu.tw/~algo/LongestCommonSubsequence.html
// DP

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int n1 = text1.size(), n2 = text2.size();
        if(n1 <= 0 || n2 <= 0) return 0;
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        for(int i = 0; i <= n1; i++) dp[i][0] = 0;
        for(int j = 0; j <= n2; j++) dp[0][j] = 0;
        
        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                if(text1[i - 1] == text2[j - 1]) 
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else 
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[n1][n2];
    }
};
