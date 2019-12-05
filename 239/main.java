// O(n^2) solution

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        if(nums == null || n <= 0) {
            return nums;
        }
        int[] result = new int[n - k + 1];
        
        for(int i = 0; i < n - k + 1; i++) {
            int temp = Integer.MIN_VALUE;
            for(int j = i; j < i + k; j++) {
                if(nums[j] > temp) {
                    temp = nums[j];
                }
            }
            
            result[i] = temp;
        }
        
        return result;
    }
}
