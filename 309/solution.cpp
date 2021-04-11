// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-309-best-time-to-buy-and-sell-stock-with-cooldown/
// DP (optimized)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN;
        int sold = 0;
        int rest = 0;
        for(auto price : prices) {
            int prev_sold = sold;
            sold = hold + price;
            hold = max(hold, rest - price);
            rest = max(rest, prev_sold);
        }
        return max(sold, rest);
    }
};
