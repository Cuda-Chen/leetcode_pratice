class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& A, int k) {
        unordered_map<int, int> m;
        for(int &a : A)
            m[a]++;
        vector<pair<int, int>> v; // {cnt, num}
        for(auto &[num, cnt] : m)
            v.push_back({cnt, num});
        ranges::sort(v);
        int idx = 0;
        while(k--) {
            if(v[idx].first == 0)
                idx++;
            v[idx].first--;
        }
        int ans = 0;
        for(auto &[cnt, num] : v) {
            if(cnt != 0)
                ans++;
        }
        return ans;
    }
};
