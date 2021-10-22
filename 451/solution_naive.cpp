// naive
// Count the occurance of characters, sort it, then output the string 
// with character count decreasingly.

class Solution {
public:
    string frequencySort(string s) {
        vector<int> cnts(128, 0);
        vector<char> chars(128);
        for(int i = 0; i < chars.size(); i++)
            chars[i] = static_cast<char>(i);
        for(char c : s) {
            cnts[static_cast<int>(c)]++;
        }
        
        vector<pair<char, int>> freqs(128); // {char, cnts}
        for(int i = 0; i < freqs.size(); i++)
            freqs[i] = {chars[i], cnts[i]};
        
        sort(freqs.begin(), freqs.end(), [](const auto &a, const auto &b) {
            return a.second > b.second;
        });
        
        string ans;
        for(int i = 0; i < freqs.size(); i++) {
            if(freqs[i].second == 0) break;
            for(int j = 0; j < freqs[i].second; j++)
                ans += freqs[i].first;
        }
        
        return ans;
    }
};
