class Solution {
public:
    int minOperations(vector<int>& A, int k) {
        return accumulate(begin(A), end(A), 0) % k;
    }
};
