// O(n) space

class Solution {
public:
    int trap(vector<int>& A) {
        int n = A.size();
        vector<int> l(n), r(n);
        for(int i = 0; i < n; i++)
            l[i] = i == 0 ? A[i] : max(A[i], l[i - 1]);
        for(int i = n - 1; i >= 0; i--)
            r[i] = i == n - 1 ? A[i] : max(A[i], r[i + 1]);

        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += min(l[i], r[i]) - A[i];
        return ans;
    }
};
