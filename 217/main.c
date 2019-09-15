// hash table with uthash

typedef struct {
    int key, count;
    UT_hash_handle hh;
} HashElement;

bool containsDuplicate(int* nums, int numsSize){
    if(nums == NULL || numsSize == 0) {
        return false;
    }
    
    HashElement *hash = NULL, *elem, *temp;
    bool result = false;
    
    for(int i = 0; i < numsSize; i++) {
        int lookupKey = nums[i];
        HASH_FIND_INT(hash, &lookupKey, elem);
        if(elem) {
            printf("found duplicate\n");
            result = true;
            break;
            printf("you should see this\n");
        }
        
        printf("adding key %d\n", nums[i]);
        elem = malloc(sizeof(HashElement));
        elem->key = nums[i];
        elem->count = 1;
        HASH_ADD_INT(hash, key, elem);
    }
    
    HASH_ITER(hh, hash, elem, temp) {
        free(elem);
    }
    
    return result;
}

