class Solution {
public:
    int longestSquareStreak(vector<int>& A) {
        ranges::sort(A);

        unordered_map<int, int> m; // {num, idx of square streaks}
        vector<vector<int>> v; // record square streaks
        int idx = 0;
        for(int a : A) {
            if(m.count(a))
                continue;

            int sr = sqrt(a);
            if(sr * sr == a && m.count(sr)) {
                int ii = m[sr];
                v[ii].push_back(a);
                m[a] = ii;
            } else {
                v.push_back({});
                v[idx].push_back(a);
                m[a] = idx;
                idx++;
            }
        }

        int ans = 0;
        for(auto a : v)
            ans = max(ans, (int)a.size());
        return ans > 1 ? ans : -1;
    }
};
