// https://labuladong.gitee.io/algo/2/21/57/
// binary search (better average-O)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = leftBound(nums, target),
            r = rightBound(nums, target);
        return {l, r};
    }
    
private:
    int leftBound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] < target)
                l = mid + 1;
            else if(nums[mid] > target)
                r = mid - 1;
            else
                r = mid - 1;
        }
        
        if(l >= nums.size() || nums[l] != target)
            return -1;
        return l;
    }
    
    int rightBound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] < target)
                l = mid + 1;
            else if(nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        if(r < 0 || nums[r] != target)
            return -1;
        return r;
    }
};
