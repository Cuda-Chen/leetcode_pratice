// a 26-base to decimal conversion problem

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        const int base = 26;
        int len = s.size() - 1;
        for(int i = 0; i < s.size(); i++) {
            result += (int)((int)(s[i] - 'A' + 1) * pow(26, len));
            len--;
        }
        
        return result;
    }
};
