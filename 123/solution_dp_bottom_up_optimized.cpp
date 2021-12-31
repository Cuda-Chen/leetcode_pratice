// https://www.cnblogs.com/grandyang/p/4281975.html
// DP optimized (bottom-up)

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int k = 2;
        vector<int> l(k + 1, 0), g(k + 1, 0);
        for(int i = 1; i < p.size(); i++) {
            int diff = p[i] - p[i - 1];
            for(int j = k; j >= 1; j--) {
                l[j] = max(l[j] + diff, g[j - 1] + max(0, diff));
                g[j] = max(g[j], l[j]);
            }
        }
        return g[k];
    }
};
