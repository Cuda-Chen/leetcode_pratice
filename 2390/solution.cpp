class Solution {
public:
    string removeStars(string s) {
        int cnt = 0;
        string ans;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == '*') {
                cnt++;
                continue;
            }

            if(cnt) {
                cnt--;
                continue;
            }

            ans += s[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
