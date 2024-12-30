// DP

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 1);

        for(int i = 1; i <= high; i++) {
            int tmp = 0;
            if(i - zero >= 0)
                tmp += dp[i - zero];
            if(i - one >= 0)
                tmp += dp[i - one];

            dp[i] = positive_mod(tmp, mod);
        }

        int ans = 0;
        for(int i = low; i <= high; i++) {
            ans += positive_mod(dp[i], mod);
            ans = positive_mod(ans, mod);
        }
        return ans;
    }

private:
    int mod = 1e9 + 7;

    int positive_mod(int i, int n) {
        return (i % n + n) % n;
    }
};
