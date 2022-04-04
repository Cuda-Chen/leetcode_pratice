// DP (top-down)

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        m = vector<vector<int>>(n1 + 1, vector<int>(n2 + 1));
        return helper(s1, n1, s2, n2);
    }
    
private:
    vector<vector<int>> m;
    
    int helper(string &s1, int i, string &s2, int j) {
        if(m[i][j]) return m[i][j];
        
        int tmp;
        if(i == 0 && j == 0)
            tmp = 0;
        else if(i == 0)
            tmp = helper(s1, i, s2, j - 1) + s2[j - 1];
        else if(j == 0)
            tmp = helper(s1, i - 1, s2, j) + s1[i - 1];
        else
            tmp = (s1[i - 1] == s2[j - 1])
            ? helper(s1, i - 1, s2, j - 1)
            : min(helper(s1, i - 1, s2, j) + s1[i - 1],
                  helper(s1, i, s2, j - 1) + s2[j - 1]);
        return m[i][j] = tmp;
    }
};
