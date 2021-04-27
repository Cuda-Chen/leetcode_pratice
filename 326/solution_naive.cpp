// naive
// Note you should use long to prevent overflow.

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        
        long base = 3;
        while(base <= n) {
            if(base == n)
                return true;
            base *= 3;
        }
        
        return false;
    }
};
