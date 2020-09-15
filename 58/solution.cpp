// Use stringstream to tokenize the word
// Then get the length of last word
// (You can get the last word by using
// while loop)

class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        while(ss >> word);
        return word.size();
    }
};
