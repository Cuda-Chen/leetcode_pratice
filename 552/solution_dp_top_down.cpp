// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-552-student-attendance-record-ii/
// DP (top-down)

class Solution {
public:
    int checkRecord(int n) {
        dp = vector<vector<int>>(n + 1, vector<int>(6, 0));
        return dfs(n, 1, 2);
    }
    
private:
    vector<vector<int>> dp;
    int kMod = 1e9 + 7;
    
    int dfs(int n, int A, int L) {
        if(n == 0) return 1;
        int key = A * 3 + L;
        if(dp[n][key]) return dp[n][key];
        long ans = 0;
        
        ans += dfs(n - 1, A, 2);
        if(A > 0) ans += dfs(n - 1, A - 1, 2);
        if(L > 0) ans += dfs(n - 1, A, L - 1);
        
        return dp[n][key] = ans % kMod;
    }
};
