// two sum variant
// Use array to substitude set
// Of course, sometimes the constraints will help you

#define MAX_SIZE 100001

int sum(int *arr, int arrSize) {
    int i, summation = 0;
    for(i = 0; i != arrSize; i++) {
        summation += arr[i];
    }
    return summation;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize){
    *returnSize = 2;
    int* result = (int *)malloc(sizeof(int) * 2);
    int sum1 = sum(A, ASize);
    int sum2 = sum(B, BSize);
    int diff = (sum1 - sum2) / 2;
    int s[MAX_SIZE] = {0}; // a 'set' to store the unique element in array A
    int i;
    for(i = 0; i != ASize; i++) {
        s[A[i]]++;
    }
    
    printf("%d %d\n", sum1, sum2);
    
    for(i = 0; i != BSize; i++) {
        int target = B[i] + diff;
        if(target > 0 && target < MAX_SIZE && s[target]) {
            printf("%d", target);
            result[0] = target;
            result[1] = B[i];
        }
    }
    
    return result;
}
