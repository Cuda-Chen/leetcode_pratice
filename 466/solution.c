// DP
// https://leetcode.com/problems/count-the-repetitions/discuss/95398/c-solution-inspired-by-70664914-with-organized-explanation

int getMaxRepetitions(char * s1, int n1, char * s2, int n2){
    int *repeatCount = (int *)malloc(sizeof(int) * (n1 + 1));
    int *nextIndex = (int *)malloc(sizeof(int) * (n1 + 1));
    for(int i = 0; i < (n1 + 1); i++) {
        repeatCount[i] = 0;
        nextIndex[i] = 0;
    }
    int j = 0, count = 0;
    
    for(int k = 1; k <= n1; k++) {
        for(int i = 0; i < strlen(s1); i++) {
            if(s1[i] == s2[j]) {
                j++;
                if(j == strlen(s2)) {
                    j = 0;
                    count++;
                }
            }
        }
        
        repeatCount[k] = count;
        nextIndex[k] = j;
        for(int start = 0; start < k; start++) {
            if(nextIndex[start] == j) {
                int prefixCount = repeatCount[start];
                int patternCount = (n1 - start) / (k - start) * (repeatCount[k] - prefixCount);
                int suffixCount = repeatCount[start + (n1 - start) % (k - start)] - prefixCount;
                return (prefixCount + patternCount + suffixCount) / n2;
            }
        }
    }
    
    return repeatCount[n1] / n2;
}
