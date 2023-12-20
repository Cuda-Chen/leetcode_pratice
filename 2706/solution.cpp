class Solution {
public:
    int buyChoco(vector<int>& A, int money) {
        sort(A.begin(), A.end());
        int ans = money - (A[0] + A[1]);
        return ans < 0
            ? money
            : ans;
    }
};
