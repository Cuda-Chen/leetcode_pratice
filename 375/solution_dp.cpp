// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-375-guess-number-higher-or-lower-ii/
// DP
// You can use reference to be faster.
class Solution {
public:
    int getMoneyAmount(int n) {
        cache = vector<vector<int>>(n + 2, vector<int>(n + 2, INT_MAX));
        
        return dp(1, n);
    }
    
private:
    vector<vector<int>> cache;
    
    int dp(int l, int r) {
        if(l >= r) return 0;
        int &temp = cache[l][r];
        if(temp != INT_MAX) return temp;
        for(int x = l; x <= r; x++)
            temp = min(temp, x + max(dp(l, x - 1), dp(x + 1, r)));
        return temp;
    }
};
