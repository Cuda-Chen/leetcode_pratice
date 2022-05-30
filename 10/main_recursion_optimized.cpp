// recursion optimized

#define EXPR (s[0] == p[0] || p[0] == '.')

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())
            return s.empty();
        else if(p.size() > 1 && p[1] == '*')
            return isMatch(s, p.substr(2)) ||
                (!s.empty() && EXPR) &&
                isMatch(s.substr(1), p);
        return !s.empty() &&
            EXPR &&
            isMatch(s.substr(1), p.substr(1));
    }
};
