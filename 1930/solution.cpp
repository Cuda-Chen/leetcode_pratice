class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, vector<int>> m; // {letter, indices}
        int n = s.size();
        for(int i = 0; i < n; i++) {
            char c = s[i];
            if(!m.count(c))
                m[c] = {};
            m[c].push_back(i);
        }

        int ans = 0;
        unordered_set<string> seen; // record the existing palindroms
        for(auto &[c, v] : m) {
            int sz = v.size();
            if(sz < 2)
                continue;
            for(int i = 1; i < sz; i++) {
                int start = v[i - 1];
                int end = v[i];
                for(int j = start + 1; j < end; j++) {
                    char t = s[j];
                    string tmp;
                    tmp += c;
                    tmp += t;
                    tmp += c;
                    if(seen.count(tmp))
                        continue;
                    seen.insert(tmp);
                    ans++;
                }
            }

            if(sz >= 3) {
                string tmp(3, c);
                seen.insert(tmp);
                ans++;
            }
        }
        return ans;
    }
};
