// DP (top-down)

class Solution {
public:
    string stoneGameIII(vector<int>& A) {
        vector<int> dp(A.size(), INT_MIN);
        int tmp = f(A, 0, dp);
        return tmp > 0 ? "Alice"
            : tmp < 0 ? "Bob" : "Tie";
    }

private:
    int f(vector<int> &A, int idx, vector<int> &dp) {
        int n = A.size();
        if(idx >= n)
            return 0;
        if(dp[idx] != INT_MIN)
            return dp[idx];

        int sum = 0;
        for(int i = idx; i < idx + 3 && i < n; i++) {
            sum += A[i];
            dp[idx] = max(dp[idx], sum - f(A, i + 1, dp));
        }

        return dp[idx];
    }
};
