// divide and conquer

inline int min(int a, int b) {
    return a < b ? a : b;
}

char *longestCommonPrefixHelper(char **strs, int left, int right);
char *commonPrefix(char *str1, char *str2);

char * longestCommonPrefix(char ** strs, int strsSize){
    if(strs == NULL || strsSize <= 0) {
        return "";
    }
    
    return longestCommonPrefixHelper(strs, 0, strsSize - 1);
}

char *longestCommonPrefixHelper(char **strs, int left, int right) {
    if(left == right) {
        return strs[left];
    } else {
        int mid = (left + right) / 2;
        char *str1 = longestCommonPrefixHelper(strs, left, mid);
        char *str2 = longestCommonPrefixHelper(strs, mid + 1, right);
        return commonPrefix(str1, str2);
    }
}

char *commonPrefix(char *str1, char *str2) {
    int minimum = min(strlen(str1), strlen(str2));
    char *result;
    
    for(int i = 0; i < minimum; i++) {
        if(str1[i] != str2[i]) {
            result = (char *)malloc((i + 1) * sizeof(char));
            strncpy(result, str1, i);
            result[i] = '\0';
            return result;
        }
    }
    
    result = (char *)malloc((minimum + 1) * sizeof(char));
    strncpy(result, str1, minimum);
    result[minimum] = '\0';
    return result;
}

