// binary search the lower/upper bound indices of zeroes

class Solution {
public:
    int maximumCount(vector<int>& A) {
        auto it = A.begin();
        int l = lower_bound(A.begin(), A.end(), 0) - it; // the lower index of zeroes
        int r = upper_bound(A.begin(), A.end(), 0) - it; // the upper index of zeroes
        return std::max(
            l,
            (int)A.size() - r
        );
    }
};
