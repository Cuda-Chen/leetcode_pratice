// one pass hash table solution with uthash

typedef struct {
    int value;
    int index;
    UT_hash_handle hh;
} hashTable;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    if(nums == NULL || numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 2;
    int *result = (int *)malloc(*returnSize * sizeof(int));
    
    hashTable *hash = NULL, *elem, *temp;
    
    for(int i = 0; i < numsSize; i++) {
        int lookupKey = nums[i];
        int complement = target - lookupKey;
        HASH_FIND_INT(hash, &complement, elem);
        if(elem) {
            result[0] = elem->index;
            result[1] = i;
            break;
        }
        
        elem = malloc(sizeof(hashTable));
        elem->value = nums[i];
        elem->index = i;
        HASH_ADD_INT(hash, value, elem);
    }
    
    HASH_ITER(hh, hash, elem, temp) {
        free(elem);
    }
    
    return result;
}


