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

__global__ void prepareData(int *dp, int n) {
  for(int i = blockIdx.x * blockDim.x + threadIdx.x; i < n; i += blockDim.x * gridDim.x) {
    for(int j = blockIdx.y * blockDim.y + threadIdx.y; j < n; j+= blockDim.y * gridDim.y) {
      dp[i * n + j] = 0;
    }
  }
}

__global__ void setData(int *dp, int n) {
  for(int i = blockIdx.x * blockDim.x + threadIdx.x; i < n; i += blockDim.x * gridDim.x) {
    dp[i * n + i] = 1;
  }
}

__global__ void helperKernel(char *S, int *dp, int n, long kMod, int len) {
  for(int i = blockIdx.x * blockDim.x + threadIdx.x; i < n - len; i += blockDim.x * gridDim.x) {
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
              dp[i * n + j] += 1;
          } else if(left > right) {
              dp[i * n + j] += 2;
          } else {
              dp[i * n + j] -= dp[(left + 1) * n + (right - 1)];
          }
       } else {
           dp[i * n + j] = dp[i * n + (j - 1)] + dp[((i + 1) * n) + j] - dp[(i + 1) * n + (j - 1)];
       }
       
       dp[i * n + j] = (dp[i * n + j] + kMod) % kMod; // perform positive modulo
   }
   //__syncthreads();
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

    clock_t t;
    t = clock();    
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
    t = clock() - t;
    printf("execution time: %f\n", ((float)t / CLOCKS_PER_SEC));
    
    // GPU part
    int *h_dp = (int *)malloc(n * n * sizeof(int));
    int *d_dp;
    char *d_S;

    checkError(cudaMalloc(&d_dp, n * n * sizeof(int)));
    checkError(cudaMalloc(&d_S, n * sizeof(char)));

    checkError(cudaMemcpy(d_dp, h_dp, n * n * sizeof(int), cudaMemcpyHostToDevice));
    checkError(cudaMemcpy(d_S, S, n * sizeof(char), cudaMemcpyHostToDevice));

    const dim3 blockSize(n, n, 1);
    prepareData<<<1, blockSize>>>(d_dp, n);
    setData<<<1, n>>>(d_dp, n);

    cudaEvent_t start, stop;
    float elapsedTime;
    checkError(cudaEventCreate(&start));
    checkError(cudaEventCreate(&stop));

    checkError(cudaEventRecord(start, 0));
    for(int len = 1; len <= n; len++) {
        helperKernel<<<1, n>>>(d_S, d_dp, n, kMod, len);
    }
    checkError(cudaDeviceSynchronize());
    checkError(cudaEventRecord(stop, 0));
    checkError(cudaEventSynchronize(stop));
    checkError(cudaEventElapsedTime(&elapsedTime, start, stop));
    printf("execution time: %f\n", (elapsedTime / 1000.0));
    checkError(cudaEventDestroy(start));
    checkError(cudaEventDestroy(stop));

    checkError(cudaMemcpy(h_dp, d_dp, n * n * sizeof(int), cudaMemcpyDeviceToHost));

    for(int i = 0; i < n * n; i++) {
        if(h_dp[i] != dp[i]) {
            puts("result of GPU is inconsistant to CPU");
            break;
        }
    }
    printf("value of h_dp[0][n - 1]: %d\n", h_dp[(0 * n) + (n - 1)]);

    cudaFree(d_dp);
    cudaFree(d_S);

    free(h_dp);

    return dp[(0 * n) + (n - 1)];
}

int main() {
    //char *input = "bccb";
    //char *input = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";
    char *input = "babbdbccbaacdbddaabdccdbacdbcdbacdaccdcbaacadbcbddbcccbbabbababdcadacdbbcbabdbaddadaababbaacddbacaaddbcaabbdbdddcbbbacbbbcbadcdadcadcdaccdcccaacadbacbaaaadcdabbbacdcbbdcbddbabacaabaadcbaaadbddbdcbbbcaacdcdbbbcdccbcdaabbddacbdcdbdcacbbdbccbccbddcacdabdcdddcbcacbadabccabaddacaaaacaabdcdbccbbdcdccbbacacaaabcdddaaaabcdbaccddabcaabcaaacacaddccbdddabbcbcaacbdcacddbdcbddbaccadbdacbaccabccdcdadacbdaccccbbccaadabacdbcbdcbadddcbcbcdbdbcdabcaacdcbbdbbbbaddbcdaaacabacaddaaccccbadbacbcbdcdacbbdbaaccdcddbcbdbbbbcbbbaaadbdbdbcbdabaacccccbddbbcccaadcbdcaacacccbcdddcbcbdacbbccdbaadddaacccbcbdadacdcdcacdccabbbdaabacdadccdadbdbcbbdcbcabdcbdccbbadbddbbbbddadbabdccbbdcbacabbbcabbcdbcabdbdbabcbddaaacacadcbcbadbdabbbddcbcbdcaacabcdbccddacbcaccadcdccaaaababccaaacbcaaaccdcaacdabddbbcbbbcccaccdaccdcbabbbdddccbcadddaaabdabacddacdbbaacbdbacaaacaaabbbcaaccddccddacabadbddcddadbbccadcdcaaccddbdabbdbddacabaacccdbdbdaccabbbcadbccccdaabbcbaacacccdcbcbabaadcbacaacbbcbccbdcdacdacddcbccdcaccaabcdbacbbdcbadabcccadadddbcaca";
    printf("input string length: %d\n", strlen(input));
    //clock_t t;
    //t = clock();
    int result = countPalindromicSubsequences(input);
    //t = clock() - t;
    //printf("execution time: %f\n", ((float)t / CLOCKS_PER_SEC));
    printf("Output: %d\n", result);
    return 0;
}
