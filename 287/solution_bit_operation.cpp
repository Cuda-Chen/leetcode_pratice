// https://www.cnblogs.com/grandyang/p/4843654.html
// bit operation

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int bit = (1 << i), cnt1 = 0, cnt2 = 0;
            for(int k = 0; k < nums.size(); k++) {
                if(bit & k) cnt1++;
                if(bit & nums[k]) cnt2++;
            }
            if(cnt2 > cnt1) ans += bit;
        }
        return ans;
    }
};
