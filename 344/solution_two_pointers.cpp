// two pointers
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            s[l] ^= s[r] ^= s[l] ^= s[r];
            l++;
            r--;
        }
    }
};
