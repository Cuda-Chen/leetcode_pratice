class Solution {
public:
    string largestOddNumber(string s) {
        int idx = -1;
        for(int i = s.size() - 1; i >= 0; i--) {
            if((s[i] - '0') % 2 == 1) {
                idx = i;
                break;
            }
        }

        if(idx == -1)
            return "";
        string ans = s.substr(0, idx + 1);
        return ans;
    }
};
