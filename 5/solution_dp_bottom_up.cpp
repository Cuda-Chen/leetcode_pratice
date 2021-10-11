// https://www.cnblogs.com/grandyang/p/4464476.html
// DP (bottom-up)

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        
        int len = 1, l = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
            for(int j = 0; j < i; j++) {
                dp[j][i] = (s[i] == s[j]) && (i - j < 2 || dp[j + 1][i - 1]);
                if(dp[j][i] && len < i - j + 1) {
                    len = i - j + 1;
                    l = j;
                }
            }
        }
        
        return s.substr(l, len);
    }
};
