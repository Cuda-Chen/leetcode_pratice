// greedy

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans = 0;
        for(int i = 1; i < p.size(); i++)
            ans += max(0, p[i] - p[i - 1]);
        return ans;
    }
};
