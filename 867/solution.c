// https://leetcode.com/problems/transpose-matrix/discuss/581517/C-%3A-beats-100-simple-and-short

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    int r = ASize, c = *AColSize, **a = calloc(1, sizeof(int *[c]));
    *returnColumnSizes = malloc(sizeof(int [c]));
    for(int j = 0; j < c; j++) {
        a[j] = calloc(1, sizeof(int [r]));
        (*returnColumnSizes)[j] = r;
        for(int i = 0; i < r; i++) {
            a[j][i] = A[i][j];
        }
    }
    return *returnSize = c, a;
}
