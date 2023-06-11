// https://zxi.mytechroad.com/blog/two-pointers/leetcode-992-subarrays-with-k-different-integers/
// two pointers + indirection

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int k) {
        auto subarrays = [&A](int k) {
            int n = A.size();
            vector<int> cnt(n + 1);
            int ans = 0, i = 0;
            for(int j = 0; j < n; j++) {
                if(cnt[A[j]]++ == 0)
                    k--;
                while(k < 0) {
                    if(--cnt[A[i++]] == 0)
                        k++;
                }
                ans += j - i + 1;
            }
            return ans;
        };
        return subarrays(k) - subarrays(k - 1);
    }
};
