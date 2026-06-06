class Solution {
public:
    vector<int> leftRightDifference(vector<int>& A) {
        int n = A.size();
        vector<int> l(n), r(n);
        for(int i = 1; i < n; i++)
            l[i] = l[i - 1] + A[i - 1];
        for(int i = n - 2; i >= 0; i--)
            r[i] = r[i + 1] + A[i + 1];

        vector<int> ans(n);
        for(int i = 0; i < n; i++)
            ans[i] = abs(l[i] - r[i]);
        return ans;
    }
};
