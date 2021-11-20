// https://www.cnblogs.com/grandyang/p/8319913.html
// DP (top-down)

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        dp = vector<vector<int>>(n, vector<int>(n, 0));
        return helper(s, 0, n - 1);
    }
    
private:
    vector<vector<int>> dp;
    
    int helper(string &s, int i, int j) {
        if(i > j) return 0;
        if(dp[i][j]) return dp[i][j];
        
        dp[i][j] = 1 + helper(s, i + 1, j);
        for(int k = i + 1; k <= j; k++) {
            if(s[k] == s[i])
                dp[i][j] = min(dp[i][j], helper(s, i + 1, k - 1) + helper(s, k, j));
        }
        
        return dp[i][j];
    }
};
