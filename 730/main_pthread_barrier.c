#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

/* https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-730-count-different-palindromic-subsequences/ */

#define MAX_THREAD 4

long kMod = 1000000007;
char *str; // input string
int *dp; // DP array
int n; // length of DP array
int len; // current length
pthread_barrier_t barrier;

typedef struct Argu {
    int low;
    int high;
    double time;
} Argu;

void *helper(void *arg) {
    //pthread_mutex_lock(&work_mutex);
    int thread_id = (int)arg;

    int start_num;
    int end_num;
    int res;

    for(int len = 1; len <= n; len++) {
        int m = n - len;
        if(thread_id == MAX_THREAD - 1) {
            start_num = (m / MAX_THREAD) * thread_id;
            end_num = (m / MAX_THREAD) * (thread_id + 1) + (m % MAX_THREAD);
        } else {
            start_num = (m / MAX_THREAD) * thread_id;
            end_num = (m / MAX_THREAD) * (thread_id + 1);
        }

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

        res = pthread_barrier_wait(&barrier);
        if (res != 0 && res != PTHREAD_BARRIER_SERIAL_THREAD) {
	    	printf("Error could not wait on barrier\n");
	    	exit(EXIT_FAILURE);
	}
    }
    
    res = pthread_barrier_wait(&barrier);
    if (res != 0 && res != PTHREAD_BARRIER_SERIAL_THREAD) {
   	printf("Error could not wait on barrier\n");
    	exit(EXIT_FAILURE);
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

    // initialize barrier
    res = pthread_barrier_init(&barrier, NULL, MAX_THREAD);
    if(res != 0) {
        perror("barrier initialization failed");
        exit(EXIT_FAILURE);
    }

    // initialize attribute object
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    struct timespec start, finish;
    double elapsed;
    clock_gettime(CLOCK_MONOTONIC, &start);
        // create n threads
        for(int i = 0; i < MAX_THREAD; i++) {
            res = pthread_create(&(threads[i]), &attr, helper, (void *)i);
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
    
    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("execution time: %f with %d threads\n", elapsed, MAX_THREAD);
   
    pthread_attr_destroy(&attr);
    pthread_barrier_destroy(&barrier);
 
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
