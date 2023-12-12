class Solution {
public:
    int maxProduct(vector<int>& A) {
        int ans = 0;
        int idx = -1, mx = INT_MIN;
        int n = A.size();
        for(int i = 0; i < n; i++) {
            if(mx < A[i]) {
                mx = A[i];
                idx = i;
            }
        }
        for(int i = 0; i < n; i++) {
            if(A[i] == mx && idx != i) {
                return (mx - 1) * (mx - 1);
            }
        }

        int mx_2nd = INT_MIN;
        for(int i = 0; i < n; i++) {
            int tmp = A[i];
            if(mx_2nd < tmp && tmp < mx) {
                mx_2nd = tmp;
            }
        }
        return (mx - 1) * (mx_2nd - 1);
    }
};
