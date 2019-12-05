/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int n = numsSize;
    if(nums == NULL || n <= 0) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = n - k + 1;
    int *result = (int *)malloc((*returnSize) * sizeof(int));
    
    
    for(int i = 0; i < *returnSize; i++) {
        int temp = INT_MIN;
        for(int j = i; j < i + k; j++) {
            if(nums[j] > temp) {
                temp = nums[j];
            }
        }
        result[i] = temp;
    }
    
    return result;
}
