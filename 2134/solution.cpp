class Solution {
public:
    int minSwaps(vector<int>& A) {
        int cnt = std::accumulate(begin(A), end(A), 0); // count of 1's

        int n = A.size();
        int tmp = 0;
        for(int i = 0; i < cnt; i++)
            tmp += A[i % n];
        int ans = cnt - tmp;

        for(int i = 1; i < n; i++) {
            tmp -= A[(i - 1) % n];
            tmp += A[(i + cnt - 1) % n];
            ans = min(ans, cnt - tmp);
        }
        return ans;
    }
};
