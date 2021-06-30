// https://www.cnblogs.com/grandyang/p/4629032.html
// DP

class Solution {
public:
    int countDigitOne(int n) {
        long ans = 0, a = 1, b = 1;
        
        while(n > 0) {
            ans += (n + 8) / 10 * a + (n % 10 == 1) * b;
            b += (n % 10) * a;
            a *= 10;
            n /= 10;
        }
        
        return (int) ans;
    }
};
