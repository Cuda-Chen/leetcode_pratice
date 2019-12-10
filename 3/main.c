// sliding window optimized (ASCII 128)

#define MAGIC 128

inline int max(const int a, const int b) {
    return a > b ? a : b;
}

int lengthOfLongestSubstring(char * s){
    int n = strlen(s), result = 0;
    if(s == NULL) {
        return result;
    }
    int index[MAGIC] = { -1 };
    
    for(int j = 0, i = 0; j < n; j++) {
        i = max(i, index[s[j]]);
        result = max(result, j - i + 1);
        index[s[j]] = j + 1;
    }
    
    return result;
}

