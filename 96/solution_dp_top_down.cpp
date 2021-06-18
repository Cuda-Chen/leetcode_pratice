// DP (top-down)
class Solution {
public:
    int numTrees(int n) {
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        return count(1, n);
    }
    
private:
    vector<vector<int>> dp;
    int count(int lo, int hi) {
        if(lo > hi) return 1;
        if(dp[lo][hi]) return dp[lo][hi];
        
        int ans = 0;
        for(int i = lo; i <= hi; i++) {
            int left = count(lo, i - 1);
            int right = count(i + 1, hi);
            ans += left * right;
        }
        
        return dp[lo][hi] = ans;
    }
};
