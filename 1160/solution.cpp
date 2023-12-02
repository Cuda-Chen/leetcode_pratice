class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> m;
        for(char c : chars)
            m[c]++;
        int ans = 0;
        for(string w : words) {
            unordered_map<char, int> tmp(m);
            bool flag = true;
            for(char c : w) {
                if(!tmp.count(c) || tmp[c] <= 0) {
                    flag = false;
                    break;
                }
                tmp[c]--;
            }
            if(flag)
                ans += (int)w.size();
        }
        return ans;
    }
};
