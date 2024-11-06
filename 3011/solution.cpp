class Solution {
public:
    bool canSortArray(vector<int>& A) {
        vector<pair<int, int>> v; // store the min/max of each segment
        v.push_back({A[0], A[0]});
        for(int a : A) {
            if(__builtin_popcount(a) != __builtin_popcount(v.back().first)) {
                v.push_back({a, a});
                continue;
            }

            v.back().first = min(v.back().first, a);
            v.back().second = max(v.back().second, a);
        }

        for(int i = 1; i < v.size(); i++) {
            if(v[i - 1].second > v[i].first)
                return false;
        }
        return true;
    }
};
