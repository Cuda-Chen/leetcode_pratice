class Solution {
public:
    string compressedString(string s) {
        string ans;
        int l = 0, r = 0;
        while(r < s.size()) {
            while(s[l] == s[r]) {
                r++;
                if((r - l) == 9)
                    break;
            }

            int len = r - l;
            ans += to_string(len) + s[l];
            l = r;
        }
        return ans;
    }
};
