#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-730-count-different-palindromic-subsequences/ */

#include "cuda.h"
#include "cuda_runtime.h"

long kMod = 1000000007;

inline void checkError(cudaError_t status) {
    if(status != cudaSuccess) {
        fprintf(stderr, "Cuda failure %s:%d:%s\n", __FILE__, __LINE__, cudaGetErrorString(status));
    }
}

__global__ void helperKernel(char *S, int *dp, int n, long kMod) {
   for(int len = (blockIdx.x * blockDim.x + threadIdx.x) + 1; len <= n; len += blockDim.x * gridDim.x) {
       for(int i = blockIdx.y * blockDim.y + threadIdx.y; i < n - len; i += blockDim.y * gridDim.y) {
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
}

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
    
    // GPU part
    int *h_dp = (int *)malloc(n * n * sizeof(int));
    int *d_dp;
    char *d_S;
    const dim3 blockSize(1, 1);
    const dim3 gridSize(n / blockSize.x + 1, n / blockSize.y + 1);

    // initialize the value of each element to 0
    for(int i = 0; i < n * n; i++) {
        h_dp[i] = 0;
    }
    
    // one char itself is its palindrom
    for(int i = 0; i < n; i++) {
        h_dp[(i * n) + i] = 1;
    }

    checkError(cudaMalloc(&d_dp, n * n * sizeof(int)));
    checkError(cudaMalloc(&d_S, n * sizeof(char)));

    checkError(cudaMemcpy(d_dp, h_dp, n * n * sizeof(int), cudaMemcpyHostToDevice));
    checkError(cudaMemcpy(d_S, S, n * sizeof(char), cudaMemcpyHostToDevice));

    helperKernel<<<1, 1>>>(d_S, d_dp, n, kMod);

    checkError(cudaMemcpy(h_dp, d_dp, n * n * sizeof(int), cudaMemcpyDeviceToHost));

    for(int i = 0; i < n * n; i++) {
        if(h_dp[i] != dp[i]) {
            puts("result of GPU is inconsistant to CPU");
            break;
        }
    }
    printf("value of dp[0][n - 1]: %d\n", h_dp[(0 * n) + (n - 1)]);

    cudaFree(d_dp);
    cudaFree(d_S);

    free(h_dp);

    return dp[(0 * n) + (n - 1)];
}

int main() {
    //char *input = "bccb";
    char *input = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";
    clock_t t;
    t = clock();
    int result = countPalindromicSubsequences(input);
    t = clock() - t;
    printf("execution time: %f\n", ((float)t / CLOCKS_PER_SEC));
    printf("Output: %d\n", result);
    return 0;
}
