class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m1, m2;
        stringstream iss1(s1), iss2(s2);
        string tmp;
        while(getline(iss1, tmp, ' '))
            m1[tmp]++;
        while(getline(iss2, tmp, ' '))
            m2[tmp]++;

        vector<string> ans;
        for(auto [s, cnt] : m1) {
            if(cnt == 1 && !m2.count(s))
                ans.push_back(s);
        }
        for(auto [s, cnt] : m2) {
            if(cnt == 1 && !m1.count(s))
                ans.push_back(s);
        }

        return ans;
    }
};
