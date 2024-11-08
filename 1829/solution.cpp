class Solution {
public:
    vector<int> getMaximumXor(vector<int>& A, int maximumBit) {
        int a = (1 << maximumBit) - 1;
        int n = A.size();
        vector<int> ans(n);
        int tmp = 0;
        for(int i = 0; i < n; i++)
            tmp ^= A[i];

        for(int i = 0; i < n; i++) {
            ans[i] = tmp ^ a;
            tmp ^= A[n - i - 1];
        }

        return ans;
    }
};
