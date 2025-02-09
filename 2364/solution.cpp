class Solution {
public:
    long long countBadPairs(vector<int>& A) {
        unordered_map<int, vector<int>> m; // {A[i] - i, {idxs}}
        int n = A.size();

        // preserve the monotonicaliation of index of pairs
        for(int i = 0; i < n; i++)
            m[A[i] - i].push_back(i);

        long long ans = 0LL;
        for(auto &[_, v] : m) {
            int sz = v.size();
            for(int i = 0; i < sz; i++) {
                int idx = v[i];
                int expected = (n - idx - 1); // expected pairs or current index
                int good = (sz - i - 1); // the "good" pairs, i.e., i < j and j - i == A[j] - A[i]

                ans += (expected - good); // get # the "bad" pairs
            }
        }
        return ans;
    }
};
