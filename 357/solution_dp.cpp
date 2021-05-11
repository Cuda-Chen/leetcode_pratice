// https://zxi.mytechroad.com/blog/math/leetcode-357-count-numbers-with-unique-digits/
// DP (math)

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(!n) return 1;
        
        vector<int> f(11);
        f[1] = 10;
        f[2] = 9 * 9;
        for(int i = 3; i <= 10; i++)
            f[i] = f[i - 1] * (10 - i + 1);
        
        int result = 0;
        for(int i = 1; i <= min(10, n); i++)
            result += f[i];
        return result;
    }
};
