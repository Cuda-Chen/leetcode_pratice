class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        vector<int> c1(26), c2(26); // record character set
        for(int i = 0; i < s1.size(); i++) {
            c1[s1[i] - 'a']++;
            c2[s2[i] - 'a']++;
            if(s1[i] != s2[i])
                cnt++;
        }

        return c1 == c2 &&
           ( cnt == 0 || cnt == 2 );
    }
};
