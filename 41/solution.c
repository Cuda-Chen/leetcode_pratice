// one-pass

int firstMissingPositive(int* nums, int numsSize){
    int n = numsSize;
    for(int i = 0; i < n; i++) {
        while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
            int rightIdx = nums[i] - 1;
            int temp = nums[rightIdx];
            nums[rightIdx] = nums[i];
            nums[i] = temp;
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(nums[i] != i + 1) {
            return i + 1;
        }
    }
    
    return n + 1;
}
