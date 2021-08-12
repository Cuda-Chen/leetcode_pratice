// https://www.cnblogs.com/grandyang/p/5873525.html
// DP (top-down)

class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1) return 0;
        long temp = n;
        return (temp % 2 == 0) ? (1 + integerReplacement(temp / 2))
            : (2 + min(integerReplacement((temp + 1) / 2),
                       integerReplacement((temp - 1) / 2)));
    }
};
