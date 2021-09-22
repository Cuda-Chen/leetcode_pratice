// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-552-student-attendance-record-ii/
// DP (bottom-up)

class Solution {
public:
    int checkRecord(int n) {
        constexpr int kMod = 1e9 + 7;
        vector<long> dp(6, 1);
        
        for(int i = 1; i <= n; i++) {
            vector<long> temp(6, 0);
            for(int A = 0; A <= 1; A++) {
                for(int L = 0; L <= 2; L++) {
                    int key = getKey(A, L);
                    temp[key] += dp[getKey(A, 2)];
                    if(A > 0) temp[key] += dp[getKey(A - 1, 2)];
                    if(L > 0) temp[key] += dp[getKey(A, L - 1)];
                    temp[key] %= kMod;
                }
            }
            dp.swap(temp);
        }
        
        return dp[5];
    }
    
private:
    inline int getKey(int A, int L) { return A * 3 + L; }
};
