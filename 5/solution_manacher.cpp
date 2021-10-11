// Manacher's algorithm
// O(n) time complexity

class Solution {
public:
    string longestPalindrome(string s) {
        string t = "$#";
        for(char c : s) {
            t += c;
            t += "#";
        }
        
        vector<int> p(t.size(), 0);
        int id = 0, mx = 0, ansId = 0, ansMx = 0;
        for(int i = 1; i < p.size(); i++) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while(t[i + p[i]] == t[i - p[i]]) ++p[i];
            if(mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            if(ansMx < p[i]) {
                ansMx = p[i];
                ansId = i;
            }
        }
        
        return s.substr((ansId - ansMx) / 2, ansMx - 1);
    }
};
