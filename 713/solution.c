// sliding window

int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    int result = 0;
    if(k <= 1) {
        return result;
    }
    int product = 1, left = 0;
    
    for(int right = 0; right < numsSize; right++) {
        product *= nums[right];
        while(product >= k) {
            product /= nums[left++];
        }
        
        result += right - left + 1;
    }
    
    return result;
}


