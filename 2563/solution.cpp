// sort + binary search

class Solution {
public:
    long long countFairPairs(vector<int>& A, int lower, int upper) {
        ranges::sort(A);

        long long ans = 0;
        for(int i = 0; i < A.size(); i++) {
            int a = A[i];
            int comp1 = lower - a;
            int comp2 = upper - a + 1;
            int l = lower_bound(A.begin() + i + 1, A.end(), comp1) - A.begin();
            int r = lower_bound(A.begin() + i + 1, A.end(), comp2) - A.begin();
            ans += (r - l);
        }
        return ans;
    }
};
