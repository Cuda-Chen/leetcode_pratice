class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<vector<int>> cnt(26);
        for(int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a'].push_back(i);
        }

        int ans = 0;
        bool flag = true;
        for(auto c : cnt) {
            if(c.size() <= 1)
                continue;

            flag = false;
            ans = max(ans, c.back() - c[0] - 1);
        }
        return flag ? -1 : ans;
    }
};
