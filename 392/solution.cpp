class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size(), len = s.size();
        int idx = 0;
        for(int i = 0; i < n; i++) {
            if(s[idx] == t[i])
                idx++;
            if(idx == len)
                return true;
        }
        return (n == 0 && len == 0)
            ? true 
            : false;
    }
};
