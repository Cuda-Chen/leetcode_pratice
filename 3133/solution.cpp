// 1. Set the 0's bit of x according to the LSB of n.
// 2. Right shift n one bit.
// 3. Loop 1. and 2. until n == 0.

class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long tmp = n - 1;
        for(int i = 0; i < 64; i++) {
            if(tmp == 0)
                break;
            if((ans >> i) & 1LL)
                continue;
            
            long digit = tmp & 1;
            tmp >>= 1;
            ans |= (digit << i);
        }
        return ans;
    }
};
