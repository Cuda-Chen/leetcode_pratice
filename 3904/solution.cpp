// prefix sum

class Solution {
public:
    int firstStableIndex(vector<int>& A, int k) {
        int n = A.size();
        vector<int> suffix(n);
        int mn = INT_MAX;
        for(int i = n - 1; i >= 0; i--) {
            mn = min(mn, A[i]);
            suffix[i] = mn;
        }

        int mx = 0;
        for(int i = 0; i < n; i++) {
            mx = max(mx, A[i]);
            if(mx - suffix[i] <= k)
                return i;
        }
        return -1;
    }
};
