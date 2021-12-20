// https://labuladong.gitee.io/algo/2/21/56/
// sliding window

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for(char c : t) need[c]++;
        
        int l = 0, r = 0;
        int valid = 0;
        int start = 0, len = INT_MAX;
        while(r < s.size()) {
            char c = s[r];
            r++;
            if(need.count(c)) {
                window[c]++;
                if(window[c] == need[c])
                    valid++;
            }
            
            while(valid == need.size()) {
                if(r - l < len) {
                    len = r - l;
                    start = l;
                }
                int d = s[l];
                l++;
                if(need.count(d)) {
                    if(window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
