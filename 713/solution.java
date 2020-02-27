// sliding window

class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int result = 0;
        while(k <= 1) {
            return result;
        }
        int product = 1, left = 0;
        
        for(int right = 0; right < nums.length; right++) {
            product *= nums[right];
            while(product >= k) {
                product /= nums[left++];
            }
            
            result += right - left + 1;
        }
        
        return result;
    }
}
