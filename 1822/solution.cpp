class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt = 0, zeroes = 0;
        for(int num : nums) {
            if(num < 0)
                cnt++;
            if(num == 0) {
                zeroes = 1;
                break;
            }
        }
        if(zeroes)
            return 0;
        return (cnt & 1) ? -1 : 1;
    }
};
