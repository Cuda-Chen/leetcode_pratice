class Solution {
public:
    int minimumDifference(vector<int>& A, int k) {
        int ans = INT_MAX;
        ranges::sort(A);
        for(int i = 0; i <= A.size() - k; i++)
            ans = min(ans, A[i + k - 1] - A[i]);
        return ans;
    }
};
