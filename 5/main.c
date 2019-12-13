// expand around center

inline int max(const int a, const int b) {
    return a > b ? a : b;
}

int expandAroundCenter(char *s, int left, int right);

char * longestPalindrome(char * s){
    int n = strlen(s);
    if(s == NULL) {
        return "";
    }
    
    int left = 0, right = 0;
    for(int i = 0; i < n; i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = max(len1, len2);
        
        if(len > right - left) {
            left = i - (len - 1) / 2;
            right = i + len / 2;
        }
    }
    
    char *result = (char *)malloc((right - left + 1 + 1) * sizeof(char));
    strncpy(result, &s[left], right - left + 1);
    result[right - left + 1] = '\0';
    return result;
}

int expandAroundCenter(char *s, int left, int right) {
    while(left >= 0 && right < strlen(s) && s[left] == s[right]) {
        left--;
        right++;
    }
    
    return right - left - 1;
}


