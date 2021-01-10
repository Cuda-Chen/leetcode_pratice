// https://zxi.mytechroad.com/blog/searching/leetcode-87-scramble-string/
// DP (top-down)

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        if(freq(s1) != freq(s2)) return false;
        int l = s1.size();
        for(int i = 1; i < l; i++) {
            if(isScramble(s1.substr(0, i), s2.substr(0, i))
               && isScramble(s1.substr(i), s2.substr(i))
               || isScramble(s1.substr(0, i), s2.substr(l - i, i))
               && isScramble(s1.substr(i), s2.substr(0, l - i)))
                return true;
        }
        return false;
    }
    
    vector<int> freq(string &s) {
        vector<int> f(26, 0);
        for(char c : s) f[c - 'a']++;
        return f;
    }
};
