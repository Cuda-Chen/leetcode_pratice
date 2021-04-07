// naive

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        string a = s.substr(0, n / 2);
        string b = s.substr(n / 2, n / 2);
        
        return vowelCount(a) == vowelCount(b);
    }
    
private:
    char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    
    int vowelCount(string &str) {
        int count = 0;
        for(char c : str) {
            for(char vowel : vowels) {
                if(c == vowel)
                    count++;
            }
        }
        return count;
    }
};
