// https://www.cnblogs.com/grandyang/p/4263927.html
// bit operation
// solution 3: 00 (0) -> 01 (1) -> 10 (2) -> 00 (3), mod 3

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for(int num : nums) {
            a = (a ^ num) & ~b;
            b = (b ^ num) & ~a;
        }
        return a;
    }
};
