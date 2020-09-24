// bucker + linear scanning

class Solution {
public:
    char findTheDifference(string s, string t) {
        const int letters = 26;
        int sCount[26] = {0};
        int tCount[26] = {0};
        if(s.size() >= 1) {
            for(char c : s) {
                sCount[int(c - 'a')]++;
            }
        }
        if(t.size() >= 1) {
            for(char c : t) {
                tCount[int(c - 'a')]++;
            }
        }
        
        for(int i = 0; i < letters; i++) {
            if(tCount[i] != 0 && (sCount[i] != tCount[i])) {
                return i + 'a';
            }
        }
        return ' ';
    }
};
