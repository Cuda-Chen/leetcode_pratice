// https://www.cnblogs.com/grandyang/p/4464476.html
// DP (optimzied)

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        
        int len = 1, l = 0;
        for(int i = 0; i < n; i++) {
            int cur = max(getLen(s, i, i),
                          getLen(s, i, i + 1));
            if(len < cur) {
                len = cur;
                l = i - (len - 1) / 2;
            }
        }
        
        return s.substr(l, len);
    }
    
private:
    int getLen(string &s, int i, int j) {
        while(i >= 0 && j < s.size() && s[i] == s[j]) {
            --i;
            ++j;
        }
        return j - i - 1;
    }
};
