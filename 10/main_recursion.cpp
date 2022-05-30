// recursion

#define EXPR (s[0] == p[0] || p[0] == '.')

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())
            return s.empty();
        else if(p.size() == 1)
            return (s.size() == 1) && EXPR;

        if(p[1] != '*') {
            if(s.empty())
                return false;
            return EXPR && isMatch(s.substr(1), p.substr(1));
        }
        while(!s.empty() && EXPR) {
            if(isMatch(s, p.substr(2)))
                return true;
            s = s.substr(1);
        }

        return isMatch(s, p.substr(2));
    }
};
