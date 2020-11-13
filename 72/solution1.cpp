// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-72-edit-distance/
// DP (top-down)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        dp = vector<vector<int>>(l1 + 1, vector<int>(l2 + 1, -1));
        return minDistance(word1, word2, l1, l2);
    }
    
private:
    vector<vector<int>> dp;
    int minDistance(string &word1, string &word2, int l1, int l2) {
        if(l1 == 0) return l2;
        if(l2 == 0) return l1;
        if(dp[l1][l2] >= 0) return dp[l1][l2];
        
        int result = 0;
        if(word1[l1 - 1] == word2[l2 - 1])
            result = minDistance(word1, word2, l1 - 1, l2 - 1);
        else
            result = min(minDistance(word1, word2, l1 - 1, l2 - 1),
                         min(minDistance(word1, word2, l1 - 1, l2),
                             minDistance(word1, word2, l1, l2 - 1))) + 1;
        dp[l1][l2] = result;
        return dp[l1][l2];
    }
};
