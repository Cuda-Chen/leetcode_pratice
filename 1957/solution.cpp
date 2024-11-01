class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        char cur = 0; // record current character
        int l = 0, r = 0;
        while(r < s.size()) {
            if(cur != s[l])
                cur = s[l];

            while(s[r] == cur)
                r++;

            for(int i = 0; i < min((r - l), 2); i++)
                ans += cur;
            
            l = r;
        }
        return ans;
    }
};
