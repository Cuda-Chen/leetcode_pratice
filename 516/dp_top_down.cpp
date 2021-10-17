// https://www.cnblogs.com/grandyang/p/6493182.html
// DP (top-down)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return helper(s, 0, n - 1);
    }
    
private:
    vector<vector<int>> dp;
    
    int helper(string &s, int i, int j) {
        if(dp[i][j] != -1) return dp[i][j];
        if(i > j) return 0;
        
        if(i == j) dp[i][j] = 1;
        else if(s[i] == s[j]) dp[i][j] = helper(s, i + 1, j - 1) + 2;
        else dp[i][j] = max(helper(s, i + 1, j), helper(s, i, j - 1));
        
        return dp[i][j];
    }
};
