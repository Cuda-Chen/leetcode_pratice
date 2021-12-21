// https://leetcode-cn.com/problems/kth-smallest-instructions/solution/pai-lie-zu-he-by-euyvvl-iqvl/
// DP (bottom-up)

class Solution {
public:
    string kthSmallestPath(vector<int>& d, int k) {
        int endR = d[0], endC = d[1];
        const int N = 30;
        long long dp[N + 1][N + 1];
        for(int i = 0; i < N; i++) {
            dp[0][i] = 0;
            dp[i][0] = 1;
        }
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++)
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
        
        int startR = 0, startC = 0;
        string ans = "";
        while(startR < endR && startC < endC) {
            long long cnt = dp[endR - startR + endC - startC - 1][endR - startR];
            if(cnt >= k) {
                ans += "H";
                startC++;
            } else {
                ans += "V";
                startR++;
                k -= cnt;
            }
        }
        while(startR < endR) {
            ans += "V";
            startR++;
        }
        while(startC < endC) {
            ans += "H";
            startC++;
        }
        
        return ans;
    }
};
