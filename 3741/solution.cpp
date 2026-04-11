class Solution {
public:
    int minimumDistance(vector<int>& A) {
        unordered_map<int, int> m;
        int n = A.size();
        for(int i = 0; i < n; i++)
            m[A[i]].push_back(i);

        int ans = INT_MAX;
        for(auto &[_, v] : m) {
            int sz = v.size();
            if(sz < 3)
                continue;
            for(int i = 0; i < sz - 2; i++) {
                /* As the order of indices of tuple is monotonic increasing,
                 * abs(i - j) + abs(j - k) + abs(k - i) =
                 * (j - i) + (k - j) + (k - i) =
                 * -2i + 2k =
                 * 2(k - i)
                 */
                ans = min(ans, 2 * (v[i + 2] - v[i]));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
