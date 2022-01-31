// naive
// Sum up the money of each customer

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(auto account : accounts) {
            int temp = accumulate(begin(account), end(account), 0);
            ans = max(ans, temp);
        }
        return ans;
    }
};
