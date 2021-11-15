// https://www.cnblogs.com/grandyang/p/4263927.html
// bit operation
// solution 2: one, two, and three occurance, then return one

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        for(int num : nums) {
            two |= one & num;
            one ^= num;
            three = one & two;
            one &= ~three;
            two &= ~three;
        }
        return one;
    }
};
