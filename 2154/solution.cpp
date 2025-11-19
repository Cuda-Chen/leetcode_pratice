class Solution {
public:
    int findFinalValue(vector<int>& A, int orig) {
        unordered_set<int> m{begin(A), end(A)};
        while(m.count(orig))
            orig *= 2;
        return orig;
    }
};
