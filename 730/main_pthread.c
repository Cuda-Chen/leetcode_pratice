#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

/* https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-730-count-different-palindromic-subsequences/ */

#define MAX_THREAD 1

long kMod = 1000000007;
char *str; // input string
int *dp; // DP array
int n; // length of DP array
int len; // current length
int part; // which number of thread

void *helper(void *arg) {
    int thread_part = part++;
    for(int i = thread_part * (n / MAX_THREAD); i < (thread_part + 1) * ((len - n) / MAX_THREAD); i++) {
        int j = i + len;
        if(str[i] == str[j]) {
            dp[i * n + j] = dp[(i + 1) * n + (j - 1)] * 2;
            int left = i + 1;
            int right = j - 1;

            while(left <= right && str[left] != str[i]) {
                left++;
            }
            while(left <= right && str[right] != str[i]) {
                right--;
            }

            if(left == right) {
                dp[i * n + j] += 1;
            } else if(left > right) {
                dp[i * n + j] += 2;
            } else {
                dp[i * n + j] -= dp[(left + 1) * n + (right - 1)];
            }
        } else {
            dp[i * n + j] = dp[i * n + (j - 1)] + dp[(i + 1) * n + j] - dp[(i + 1) * n + (j - 1)];
        }

        dp[i * n + j] = (dp[i * n + j] + kMod) % kMod; // positive modulo
    }
}

int countPalindromicSubsequences(char * S){
    n = strlen(S);
    str = S;
    dp = (int *)malloc(n * n * sizeof(int));
    
    // initialize the value of each element to 0
    for(int i = 0; i < n * n; i++) {
        dp[i] = 0;
    }
    
    // one char itself is its palindrom
    for(int i = 0; i < n; i++) {
        dp[(i * n) + i] = 1;
    }
    
    pthread_t threads[MAX_THREAD];

    for(len = 1; len <= n; len++) {
        // create n threads
        for(int i = 0; i < MAX_THREAD; i++) {
            pthread_create(&threads[i], NULL, helper, (void *)NULL);
        }

        // join n threads i.e. waiting n threads to complete
        for(int i = 0; i < MAX_THREAD; i++) {
            pthread_join(threads[i], NULL);
        }
    }
    
    return dp[(0 * n) + (n - 1)];
}

int main() {
    char *input = "bccb";
    //char *input = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";
    clock_t t;
    t = clock();
    int result = countPalindromicSubsequences(input);
    t = clock() - t;
    printf("execution time: %f\n", ((float)t / CLOCKS_PER_SEC));
    printf("Output: %d\n", result);
    return 0;
}
