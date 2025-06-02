class Solution {
public:
    int candy(vector<int>& A) {
        int n = A.size();
        vector<int> cnt(n, 1);
        for(int i = 1; i < n; i++) {
            if(A[i] > A[i - 1])
                cnt[i] = max(cnt[i], cnt[i - 1] + 1);
        }
        for(int i = n - 2; i >= 0; i--) {
            if(A[i] > A[i + 1])
                cnt[i] = max(cnt[i], cnt[i + 1] + 1);
        }
        return accumulate(begin(cnt), end(cnt), 0);
    }
};
