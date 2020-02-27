// sliding window

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int result = 0;
        if(k <= 1) {
            return result;
        }
        int product = 1, left = 0;
        
        for(int right = 0; right < nums.size(); right++) {
            product *= nums[right];
            while(product >= k) {
                product /= nums[left++];
            }
            
            result += right - left + 1;
        }
        
        return result;
    }
};
