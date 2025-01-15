class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = __builtin_popcount(num2);
        int ans = 0;
        
        // first set the bits of ans in MSB order of num1
        for(int i = 31; (cnt > 0) && (i >= 0); i--) {
            if((num1 >> i) & 1) {
                ans |= (1 << i);
                cnt--;
            }
        }
        // set the remaining count of bits of ans in LSB order
        for(int i = 0; (cnt > 0) && (i < 31); i++) {
            if(!((ans >> i) & 1)) {
                ans |= (1 << i);
                cnt--;
            }
        }

        return ans;
    }
};
