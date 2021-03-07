// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-132-palindrome-partitioning-ii/
// DP v2
// scan from middle to two sides
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, n);
        
        for(int m = 0; m < n; m++) {
            for(int d = 0; d <= 1; d++) {
                for(int i = m, j = m + d; i >= 0 && j < n && s[i] == s[j]; i--, j++)
                    dp[j] = min(dp[j], (i ? (dp[i - 1] + 1) : 0));
            }
        }
        
        return dp[n - 1];
    }
};
