class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        vector<int> p(26); // count # needed maximum characters
        for(auto w : w2) {
            vector<int> tmp(26);
            for(char c : w)
                tmp[c - 'a']++;
            for(int i = 0; i < 26; i++)
                p[i] = max(p[i], tmp[i]);
        }

        vector<string> ans;
        for(auto w : w1) {
            vector<int> tmp(26);
            for(char c : w)
                tmp[c - 'a']++;

            bool flag = true;
            for(int i = 0; i < 26; i++) {
                if(tmp[i] < p[i])
                    flag = false;
            }
            if(flag)
                ans.push_back(w);
        }
        return ans;
    }
};
