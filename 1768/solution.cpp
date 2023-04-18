class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        int n1 = w1.size(), n2 = w2.size();
        int idx1 = 0, idx2 = 0;
        string ans;
        int sw = 0;
        while(idx1 < n1 && idx2 < n2) {
            if(!sw) {
                ans += w1[idx1];
                idx1++;
                sw = 1;
            } else {
                ans += w2[idx2];
                idx2++;
                sw = 0;
            }
        }
        while(idx1 < n1) {
            ans += w1[idx1];
            idx1++;
        }
        while(idx2 < n2) {
            ans += w2[idx2];
            idx2++;
        }
        return ans;
    }
};
