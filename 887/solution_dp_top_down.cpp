// DP (top-down)
// TLE in 2022

class Solution {
public:
    int superEggDrop(int k, int n) {
        dp = vector<vector<int>>(k + 1, vector<int>(n + 1, INT_MIN));
        return helper(k, n);
    }

private:
    vector<vector<int>> dp;

    int helper(int k, int n) {
        if(k <= 0)
            return 0;
        else if(k == 1 || n <= 0)
            return n;
        if(dp[k][n] != INT_MIN)
            return dp[k][n];

        int ans = INT_MAX;
        for(int i = 1; i <= n; i++)
            ans = min(ans, 1 + max(helper(k - 1, i - 1),
                                   helper(k, n - i)));
        return dp[k][n] = ans;
    }
};
