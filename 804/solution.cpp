// brute force + set

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        if(words.size() <= 0) return 0;
        vector<string> morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        vector<string> conversions(words.size(), "");
        
        for(int i = 0; i < words.size(); i++) {
            for(char c : words[i]) {
                conversions[i] += morse[c - 'a'];
            }
        }
        
        set<string> s;
        for(int i = 0; i < conversions.size(); i++) {
            s.insert(conversions[i]);
        }
        
        return s.size();
    }
};
