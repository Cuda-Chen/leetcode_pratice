// https://www.cnblogs.com/grandyang/p/4843654.html
// binary search

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size();
        while(l < r) {
            int mid = l + (r - l) / 2, cnt = 0;
            for(int num : nums) {
                if(num <= mid) cnt++;
            }
            if(cnt <= mid) l = mid + 1;
            else r = mid;
        }
        return r;
    }
};
