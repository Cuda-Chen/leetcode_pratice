// https://labuladong.gitee.io/algo/2/21/56/
// sliding window

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        
        int l = 0, r = 0;
        int ans = 0;
        while(r < s.size()) {
            char c = s[r];
            r++;
            window[c]++;
            
            while(window[c] > 1) {
                char d = s[l];
                l++;
                window[d]--;
            }
            
            ans = max(ans, r - l);
        }
        
        return ans;
    }
};
