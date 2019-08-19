#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-730-count-different-palindromic-subsequences/ */

long kMod = 1000000007;

int countPalindromicSubsequences(char * S){
    int n = strlen(S);
    int *dp = (int *)malloc(n * n * sizeof(int));
    
    // initialize the value of each element to 0
    for(int i = 0; i < n * n; i++) {
        dp[i] = 0;
    }
    
    // one char itself is its palindrom
    for(int i = 0; i < n; i++) {
        dp[(i * n) + i] = 1;
    }
    
    for(int len = 1; len <= n; len++) {
        for(int i = 0; i < n - len; i++) {
            int j = i + len; // jth element is the end of current string
            if(S[i] == S[j]) { // if front and rear are the same
                dp[i * n + j] = dp[(i + 1) * n + (j - 1)] * 2;
                int left = i + 1;
                int right = j - 1;
                
                while(left <= right && S[left] != S[i]) {
                    left++;
                }
                while(left <= right && S[right] != S[i]) {
                    right--;
                }
                
                if(left == right) {
                    dp[(i * n) + j] += 1;
                } else if(left > right) {
                    dp[(i * n) + j] += 2;
                } else {
                    dp[(i * n) + j] -= dp[(left + 1) * n + (right - 1)];
                }
            } else {
                dp[(i * n) + j] = dp[(i * n) + (j - 1)] + dp[((i + 1) * n) + j] - dp[((i + 1) * n) + (j - 1)];
            }
            
            dp[(i * n) + j] = (dp[(i * n) + j] + kMod) % kMod; // perform positive modulo
        }
    }
    
    return dp[(0 * n) + (n - 1)];
}

int main() {
    //char *input = "bccb";
    //char *input = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";
    char *input = "babbdbccbaacdbddaabdccdbacdbcdbacdaccdcbaacadbcbddbcccbbabbababdcadacdbbcbabdbaddadaababbaacddbacaaddbcaabbdbdddcbbbacbbbcbadcdadcadcdaccdcccaacadbacbaaaadcdabbbacdcbbdcbddbabacaabaadcbaaadbddbdcbbbcaacdcdbbbcdccbcdaabbddacbdcdbdcacbbdbccbccbddcacdabdcdddcbcacbadabccabaddacaaaacaabdcdbccbbdcdccbbacacaaabcdddaaaabcdbaccddabcaabcaaacacaddccbdddabbcbcaacbdcacddbdcbddbaccadbdacbaccabccdcdadacbdaccccbbccaadabacdbcbdcbadddcbcbcdbdbcdabcaacdcbbdbbbbaddbcdaaacabacaddaaccccbadbacbcbdcdacbbdbaaccdcddbcbdbbbbcbbbaaadbdbdbcbdabaacccccbddbbcccaadcbdcaacacccbcdddcbcbdacbbccdbaadddaacccbcbdadacdcdcacdccabbbdaabacdadccdadbdbcbbdcbcabdcbdccbbadbddbbbbddadbabdccbbdcbacabbbcabbcdbcabdbdbabcbddaaacacadcbcbadbdabbbddcbcbdcaacabcdbccddacbcaccadcdccaaaababccaaacbcaaaccdcaacdabddbbcbbbcccaccdaccdcbabbbdddccbcadddaaabdabacddacdbbaacbdbacaaacaaabbbcaaccddccddacabadbddcddadbbccadcdcaaccddbdabbdbddacabaacccdbdbdaccabbbcadbccccdaabbcbaacacccdcbcbabaadcbacaacbbcbccbdcdacdacddcbccdcaccaabcdbacbbdcbadabcccadadddbcaca";
    clock_t t;
    t = clock();
    int result = countPalindromicSubsequences(input);
    t = clock() - t;
    printf("execution time: %f\n", ((float)t / CLOCKS_PER_SEC));
    printf("Output: %d\n", result);
    return 0;
}
