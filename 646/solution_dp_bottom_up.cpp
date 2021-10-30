// https://leetcode-cn.com/problems/maximum-length-of-pair-chain/solution/zui-chang-shu-dui-lian-by-leetcode/
// DP (bottom-up)

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });
        
        int n = pairs.size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(pairs[j][1] < pairs[i][0])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
