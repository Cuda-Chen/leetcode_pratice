// https://www.cnblogs.com/grandyang/p/6675879.html
// DP (top-down)
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<vector<int>> dp(n, vector<int>(m));
        vector<vector<int>> v(26);
        for(int i = 0; i < n; i++) v[ring[i] - 'a'].push_back(i);
        
        return helper(ring, key, 0, 0, v, dp);
    }
    
private:
    int helper(string &ring, string &key, int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp) {
        if(j == key.size()) return 0;
        if(dp[i][j]) return dp[i][j];
        int ans = INT_MAX, n = ring.size();
        
        for(int k : v[key[j] - 'a']) {
            int diff = abs(i - k);
            int step = min(diff, n - diff);
            ans = min(ans, step + helper(ring, key, k, j + 1, v, dp));
        }
        
        return dp[i][j] = ans + 1;
    }
};
