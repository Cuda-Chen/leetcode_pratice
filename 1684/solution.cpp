class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<int> m(begin(allowed), end(allowed));
        int ans = 0;
        for(string &w : words) {
            int flag = 1;
            for(char &c : w) {
                if(!m.count(c)) {
                    flag = 0;
                    break;
                }
            }
            ans += flag;
        }
        return ans;
    }
};
