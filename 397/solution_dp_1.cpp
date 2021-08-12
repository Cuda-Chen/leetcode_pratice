// https://www.cnblogs.com/grandyang/p/5873525.html
// DP (bottom-up)
// bitwise operation

class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1) return 0;
        long temp = n;
        int ans = 0;
        
        while(temp > 1) {
            if(temp & 1) {
                if((temp & 2) && (temp != 3))
                    temp++;
                else
                    temp--;
            } else {
                temp >>= 1;
            }
            
            ans++;
        }
        
        return ans;
    }
};
