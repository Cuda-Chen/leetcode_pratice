// https://www.cnblogs.com/grandyang/p/6493182.html
// DP (bottom-up)
// O(n) space

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> dp(n, 1);
        
        for(int i = n - 1; i >= 0; i--) {
            int len = 0;
            for(int j = i + 1; j < n; j++) {
                int temp = dp[j];
                if(s[i] == s[j]) dp[j] = len + 2;
                len = max(len, temp);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
