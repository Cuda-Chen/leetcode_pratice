// regex (TLE)

class Solution {
public:
    int countBinarySubstrings(string s) {
        // edge case
        if(s.size() <= 1) return 0;
        
        vector<string> patterns;
        int result = 0;
        int n = s.size() % 2 == 0 ? s.size() : s.size() - 1;
        for(int i = 1; i <= n / 2; i++) {
            // first pattern
            string pattern1;
            for(int j = 1; j <= i; j++) {
                pattern1 += "0";
            }
            for(int j = 1; j <= i; j++) {
                pattern1 += "1";
            }
            patterns.push_back(pattern1);
            
            // second pattern
            string pattern2;
            for(int j = 1; j <= i; j++) {
                pattern2 += "1";
            }
            for(int j = 1; j <= i; j++) {
                pattern2 += "0";
            }
            patterns.push_back(pattern2);
        }
        
        for(string &pattern : patterns) {
            std::smatch m;
            string s_copy(s);
            while (regex_search(s_copy, m, std::regex(pattern))){
                result++;
                s_copy = m.suffix().str();
            }
        }
        
        return result;
    }
};
