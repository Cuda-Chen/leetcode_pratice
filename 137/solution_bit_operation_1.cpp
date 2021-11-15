// https://www.cnblogs.com/grandyang/p/4263927.html
// bit operation
// solution 1: calculate the bit occurence then mod 3

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int sum = 0;
            for(int num : nums) 
                sum += (num >> i) & 1;
            ans |= (sum % 3) << i;
        }
        return ans;
    }
};
