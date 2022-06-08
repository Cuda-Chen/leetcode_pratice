// DP (top-down) + binary search

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

        int l = 1, r = n + 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            int broken = helper(k - 1, m - 1),
                unbroken = helper(k, n - m);
            if(broken >= unbroken)
                r = m;
            else
                l = m + 1;
        }
        return dp[k][n] = 1 + helper(k - 1, l - 1);
    }
};
