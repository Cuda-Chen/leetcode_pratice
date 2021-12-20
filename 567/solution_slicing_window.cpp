// https://labuladong.gitee.io/algo/2/21/56/
// sliding window

class Solution {
public:
    bool checkInclusion(string t, string s) {
        unordered_map<char, int> need, window;
        for(char c : t) need[c]++;
        
        int l = 0, r = 0;
        int valid = 0;
        while(r < s.size()) {
            char c = s[r];
            r++;
            if(need.count(c)) {
                window[c]++;
                if(window[c] == need[c])
                    valid++;
            }
            
            while(r - l >= t.size()) {
                if(valid == need.size()) return true;
                char d = s[l];
                l++;
                if(need.count(d)) {
                    if(window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        
        return false;
    }
};
