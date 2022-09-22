// shorter greedy solution

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int kInf = 101;
        vector<vector<int>> dp(T + 1, vector<int>(T + 1));
        for(int i = 0; i <= T; i++)
            for(int j = 0; j <= T; j++)
                dp[i][j] = i < j ? kInf : 0;
        for(auto &c : clips) {
            int s = min(c[0], T), e = min(c[1], T);
            for(int l = 1; l <= T; l++) {
                for(int i = 0; i <= T - l; i++) {
                    int j = i + l;
                    dp[i][j] = min(dp[i][j], dp[i][s] + 1 + dp[e][j]);
                }
            }
        }
        return dp[0][T] == kInf ? -1 : dp[0][T];
    }
};
