class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = -1;
        for(int i = 0; i < word.size(); i++) {
            if(word[i] == ch) {
                idx = i;
                break;
            }
        }
        
        if(idx != -1) {
            for(int i = 0; i <= idx / 2; i++)
                swap(word[i], word[idx - i]);
        }
        
        return word;
    }
};
