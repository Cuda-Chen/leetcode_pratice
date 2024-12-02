class Solution {
public:
    int isPrefixOfWord(string sentence, string p) {
        int idx = 1;
        stringstream ss(sentence);
        string s;
        while(getline(ss, s, ' ')) {
            if(s.starts_with(p))
                return idx;
            idx++;
        }
        return -1;
    }
};
