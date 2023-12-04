class Solution {
public:
    string largestGoodInteger(string s) {
        vector<int> cnt(10); // 0~9
        int l = 0, r = 0;
        while(r < s.size()) {
            while(s[l] == s[r])
                r++;
            if((r - l) >= 3)
                cnt[s[l] - '0']++;
            l = r;
        }
        
        int idx = -1;
        for(int i = 9; i >= 0; i--) {
            if(cnt[i] != 0) {
                idx = i;
                break;
            }
        }
        string ans;
        if(idx != -1) {
            for(int i = 0; i < 3; i++)
                ans += to_string(idx);
        }
        return ans;
    }
};
