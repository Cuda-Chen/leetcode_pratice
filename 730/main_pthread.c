#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

/* https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-730-count-different-palindromic-subsequences/ */

#define MAX_THREAD 8

long kMod = 1000000007;
char *str; // input string
int *dp; // DP array
int n; // length of DP array
int len; // current length

typedef struct Argu {
    int low;
    int high;
    double time;
} Argu;

void *helper(void *arg) {
    //pthread_mutex_lock(&work_mutex);
    //int thread_part = *(int *)arg;
    Argu data = *((Argu *)arg);

    int start_num = data.low;
    int end_num = data.high; 

    for(int i = start_num; i < end_num; i++) {
        //printf("I'm thread[%d], start_num:%d, end_num:%d\n", thread_id, start_num, end_num);
        //sleep(1);
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

    pthread_exit(NULL);
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
    int res;

    // initialize mutex
    /*res = pthread_mutex_init(&work_mutex, NULL);
    if(res != 0) {
        perror("mutex initialization failed");
        exit(EXIT_FAILURE);
    }*/

    struct timespec start, finish;
    double elapsed;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(len = 1; len <= n; len++) {
        // create n threads
        for(int i = 0; i < MAX_THREAD; i++) {
            Argu *argu = (Argu *)malloc(sizeof(Argu));
            int m = n - len;
            if(i == MAX_THREAD - 1) {
                argu->low = (m / MAX_THREAD) * i;
                argu->high = (m / MAX_THREAD) * (i + 1) + (m % MAX_THREAD);
            } else {
               argu->low = (m / MAX_THREAD) * i;
               argu->high = (m / MAX_THREAD) * (i + 1);
            }
            argu->time = 0;
            res = pthread_create(&(threads[i]), NULL, helper, (void *)argu);
            //printf("len %d thread %d created\n", len, i);
            if(res != 0) {
                perror("thread creation failed");
                exit(EXIT_FAILURE);
            }
        }
        //puts("after pthread_create");

        // join n threads i.e. waiting n threads to complete
        for(int i = 0; i < MAX_THREAD; i++) {
            res = pthread_join(threads[i], NULL);
            //printf("len %d thread %d joined\n", len, i);
            if(res != 0) {
                perror("thread join failed");
            }
        }
        //puts("after pthread_join");
    }
    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("execution time: %f with %d threads\n", elapsed, MAX_THREAD);
    
    return dp[(0 * n) + (n - 1)];
}

int main() {
    //char *input = "bccb";
    //char *input = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";
    char *input = "babbdbccbaacdbddaabdccdbacdbcdbacdaccdcbaacadbcbddbcccbbabbababdcadacdbbcbabdbaddadaababbaacddbacaaddbcaabbdbdddcbbbacbbbcbadcdadcadcdaccdcccaacadbacbaaaadcdabbbacdcbbdcbddbabacaabaadcbaaadbddbdcbbbcaacdcdbbbcdccbcdaabbddacbdcdbdcacbbdbccbccbddcacdabdcdddcbcacbadabccabaddacaaaacaabdcdbccbbdcdccbbacacaaabcdddaaaabcdbaccddabcaabcaaacacaddccbdddabbcbcaacbdcacddbdcbddbaccadbdacbaccabccdcdadacbdaccccbbccaadabacdbcbdcbadddcbcbcdbdbcdabcaacdcbbdbbbbaddbcdaaacabacaddaaccccbadbacbcbdcdacbbdbaaccdcddbcbdbbbbcbbbaaadbdbdbcbdabaacccccbddbbcccaadcbdcaacacccbcdddcbcbdacbbccdbaadddaacccbcbdadacdcdcacdccabbbdaabacdadccdadbdbcbbdcbcabdcbdccbbadbddbbbbddadbabdccbbdcbacabbbcabbcdbcabdbdbabcbddaaacacadcbcbadbdabbbddcbcbdcaacabcdbccddacbcaccadcdccaaaababccaaacbcaaaccdcaacdabddbbcbbbcccaccdaccdcbabbbdddccbcadddaaabdabacddacdbbaacbdbacaaacaaabbbcaaccddccddacabadbddcddadbbccadcdcaaccddbdabbdbddacabaacccdbdbdaccabbbcadbccccdaabbcbaacacccdcbcbabaadcbacaacbbcbccbdcdacdacddcbccdcaccaabcdbacbbdcbadabcccadadddbcaca";
    int result = countPalindromicSubsequences(input);
    printf("Output: %d\n", result);
    return 0;
}
