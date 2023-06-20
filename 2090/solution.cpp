// prefix sum

class Solution {
public:
    vector<int> getAverages(vector<int>& A, int k) {
        int n = A.size();
        printf("n: %d\n", n);
        int d = k + k + 1;
        vector<int> ans(n, -1);
        if(n < d)
            return ans;
        long tmp = 0;
        for(int i = 0; i < k + k + 1; i++)
            tmp += A[i];
        ans[k] = tmp / d;
        printf("idx: %d, ans: %d, tmp: %ld\n", k, ans[k], tmp);
        for(int i = k + 1; i < n - k; i++) {
            tmp -= A[i - k - 1];
            tmp += A[i + k];
            ans[i] = tmp / d;
            printf("idx: %d, ans: %d\n", i, ans[i]);
        }
        return ans;
    }
};
