class Solution {
public:
    long long dividePlayers(vector<int>& A) {
        long long ans = 0LL;
        int n = A.size();
        ranges::sort(A);

        int sum = A[0] + A[n - 1];
        ans += A[0] * A[n - 1];
        for(int i = 1; i < n / 2; i++) {
            if(A[i] + A[n - 1 - i] != sum)
                return -1;
            ans += A[i] * A[n - 1 - i];
        }
        return ans;
    }
};
