// 2785. Sort Vowels in a String
// counting sort

class Solution {
public:
    Solution() : is_vowel(82) {
        is_vowel['A' - 'A']++;
        is_vowel['E' - 'A']++;
        is_vowel['I' - 'A']++;
        is_vowel['O' - 'A']++;
        is_vowel['U' - 'A']++;
        is_vowel['a' - 'A']++;
        is_vowel['e' - 'A']++;
        is_vowel['i' - 'A']++;
        is_vowel['o' - 'A']++;
        is_vowel['u' - 'A']++;
    }

    string sortVowels(string s) {
        int n = s.size();
        string ans(s);
        vector<int> idxs;
        for(int i = 0; i < n; i++) {
            if(is_vowel[s[i] - 'A']) {
                is_vowel[s[i] - 'A']++;
                idxs.push_back(i);
            }
        }

        int i = 0;
        for(char c : {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'}) {
            while(is_vowel[c - 'A'] != 1) {
                ans[idxs[i]] = c;
                is_vowel[c - 'A']--;
                i++;
            }
        }
        return ans;
    }

private:
    vector<int> is_vowel;
};
