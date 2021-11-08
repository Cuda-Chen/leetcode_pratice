// https://www.cnblogs.com/grandyang/p/7439616.html
// DP (optimized)

class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        for(int i = 2; i <= n; i++) {
            while(n % i == 0) {
                ans += i;
                n /= i;
            }
        }
        return ans;
    }
};
