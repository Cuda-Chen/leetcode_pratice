// DP

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans = 0, tmp = p[0];
        for(int i = 1; i < p.size(); i++) {
            if(tmp > p[i])
                tmp = p[i];
            else
                ans = max(ans, p[i] - tmp);
        }
        return ans;
    }
};
