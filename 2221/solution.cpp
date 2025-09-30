class Solution {
public:
    int triangularSum(vector<int>& A) {
        int sz = A.size();
        while(sz != 1) {
            for(int i = 0; i < sz - 1; i++) {
                A[i] += A[i + 1];
                A[i] %= 10;
            }
            sz--;
        }
        return A[0];
    }
};
