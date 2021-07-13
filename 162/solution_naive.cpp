// naive (linear scan)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            int a = ((i - 1) < 0) ? INT_MIN : nums[i - 1];
            int b = ((i + 1) >= nums.size()) ? INT_MIN : nums[i + 1];
            
            if(nums[i] > a && nums[i] > b) {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};
