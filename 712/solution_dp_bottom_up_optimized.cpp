// DP (bottom-up, optimized)

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<int> dp(n2 + 1);
        for(int j = 1; j <= n2; j++)
            dp[j] = dp[j - 1] + s2[j - 1];
        
        for(int i = 1; i <= n1; i++) {
            int t1 = dp[0];
            dp[0] += s1[i - 1];
            for(int j = 1; j <= n2; j++) {
                int t2 = dp[j];
                dp[j] = (s1[i - 1] == s2[j - 1])
                    ? t1
                    : min(dp[j] + s1[i - 1],
                          dp[j - 1] + s2[j - 1]);
                t1 = t2;
            }
        }
        
        return dp[n2];
    }
};
