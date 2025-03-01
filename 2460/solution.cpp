class Solution {
public:
    vector<int> applyOperations(vector<int>& A) {
        int n = A.size();
        for(int i = 0; i < n - 1; i++) {
            if(A[i] == A[i + 1]) {
                A[i] *= 2;
                A[i + 1] = 0;
            }
        }

        vector<int> ans(n);
        for(int i = 0, idx = 0; i < n; i++) {
            if(A[i] != 0) {
                ans[idx] = A[i];
                idx++;
            }
        }
        return ans;
    }
};
