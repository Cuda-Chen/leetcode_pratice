// https://www.cnblogs.com/grandyang/p/7439616.html
// recursive

class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        int ans = n;
        for(int i = n - 1; i > 1; i--) {
            if(n % i == 0)
                ans = min(ans, minSteps(n / i) + i);
        }
        return ans;
    }
};
