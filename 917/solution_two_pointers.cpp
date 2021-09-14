// two pointers

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while(l <= r) {
            if(isalpha(s[l]) && isalpha(s[r])) {
                char temp = s[l];
                s[l] = s[r];
                s[r] = temp;
                l++;
                r--;
            } else if(isalpha(s[l])) {
                r--;
            } else if(isalpha(s[r])) {
                l++;
            } else {
                l++;
                r--;
            }
        }

        return s;
    }
};
