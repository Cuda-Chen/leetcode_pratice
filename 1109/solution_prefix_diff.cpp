// https://zxi.mytechroad.com/blog/math/leetcode-1109-corporate-flight-bookings/
// prefix difference

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n + 1);
        for(auto b : bookings) {
            ans[b[0] - 1] += b[2];
            ans[b[1]] -= b[2];
        }
        for(int i = 1; i < n; i++)
            ans[i] += ans[i - 1];
        ans.pop_back();
        return ans;
    }
};
