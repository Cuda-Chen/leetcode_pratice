class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        uint64_t a = 0, b = 0; // hash map
        for(int i = 0; i < n; i++) {
            a |= (1LL << A[i]);
            b |= (1LL << B[i]);
            uint64_t c = a & b;
            ans[i] = __builtin_popcountll(c);
        }
        return ans;
    }
};
