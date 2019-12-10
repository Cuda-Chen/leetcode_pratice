// sliding window optimized (hash table)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), result = 0;
        if(s.empty()) {
            return result;
        }
        unordered_map<char, int> map;
        
        for(int j = 0, i = 0; j < n; j++) {
            if(map.find(s[j]) != map.end()) {
                i = max(i, map[s[j]]);
            }
            result = max(result, j - i + 1);
            map[s[j]] = j + 1;
        }
        
        return result;
    }
};
