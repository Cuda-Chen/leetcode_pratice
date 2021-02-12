// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-115-distinct-subsequences/
// DP (bottom-up)

class Solution {
public:
    int numDistinct(string s, string t) {
        int ls = s.size(), lt = t.size();
        vector<vector<long>> dp(lt + 1, vector<long>(ls + 1));
        for(int k = 0; k <= ls; k++) {
            dp[0][k] = 1;
        }
        
        for(int i = 1; i <= lt; i++) {
            for(int j = 1; j <= ls; j++) {
                if(s[j - 1] == t[i - 1])
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        
        return dp[lt][ls];
    }
};
