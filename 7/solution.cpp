// w/o any 64-bit-long data type

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0) {
            int a = ans;
            for(int i = 1; i < 10; i++) {
                if((ans > 0 && (INT_MAX - a) < ans) ||
                    (ans < 0 && (INT_MIN - a) > ans))
                    return 0;
                ans += a;
            }

            int tmp = x % 10;
            if((ans > 0 && (INT_MAX - ans) < tmp) ||
               (ans < 0 && (INT_MIN - ans) > tmp))
                return 0;
            ans += tmp;
            x /= 10;
        }
        return ans;
    }
};
