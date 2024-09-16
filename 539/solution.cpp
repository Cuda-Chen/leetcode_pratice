class Solution {
public:
    int findMinDifference(vector<string>& A) {
        constexpr int mm = 1440;
        vector<int> m(mm); // minute slots
        for(string a : A) {
            int idx = stoi(a.substr(0, 2)) * 60 + stoi(a.substr(3));
            m[idx]++;
        }

        vector<int> v;
        for(int i = 0; i < mm; i++) {
            if(m[i] > 1)
                return 0;
            else if(m[i] == 1)
                v.push_back(i);
        }

        int ans = INT_MAX;
        for(int i = 0; i < v.size() - 1; i++)
            ans = min(ans, v[i + 1] - v[i]);
        // check the last to first slot
        ans = min(ans, mm - (v.back() - v[0]));
        return ans;
    }
};
