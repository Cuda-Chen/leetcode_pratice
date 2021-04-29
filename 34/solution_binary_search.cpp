// binary search

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // edge cases
        if(nums.empty()) return {-1, -1};
        
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        
        // If target not exist in this array, return not found
        if(nums[l] != target) return {-1, -1};
        
        int left = l, right = l;
        for(int i = l + 1; i < nums.size(); i++) {
            if(nums[i] == target) 
                right++;
            else
                break;
        }
        
        return {left, right};
    }
};
