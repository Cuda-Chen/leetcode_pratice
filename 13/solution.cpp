// naive (traverse from back to front)

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> map = {{'I', 1},
                              {'V', 5},
                              {'X', 10},
                              {'L', 50},
                              {'C', 100},
                              {'D', 500},
                              {'M', 1000}};
        
        int n = s.size();
        int result = 0;
        for(int i = n - 1; i >= 0; i--) {
            if((i + 1 <= n - 1) && (map[s[i]] < map[s[i + 1]]))
                result -= map[s[i]];
            else
                result += map[s[i]];
        }
        return result;
    }
};
