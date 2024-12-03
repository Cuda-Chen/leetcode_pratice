class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int idx = 0; // spaces index
        for(int i = 0; i < s.size(); i++) {
            if(idx < spaces.size() && (i == (spaces[idx]))) {
                ans += " ";
                idx++;
            }
            ans += s[i];
        }
        return ans;
    }
};
