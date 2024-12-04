class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 < n2)
            return false;

        int idx1 = 0, idx2 = 0;
        while(idx1 < n1 && idx2 < n2) {
            char c1 = s1[idx1];
            char c2 = s2[idx2];

            if(c2 == c1 || c2 == ((c1 - 'a' + 1) % 26 + 'a'))
                idx2++;

            idx1++;
        }

        return idx2 == n2;
    }
};
