// greedy

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty())
            return 0;
        sort(points.begin(), points.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });
        int r = points[0][1], ans = 1;
        for(auto p : points) {
            if(r < p[0]) {
                ans++;
                r = p[1];
            }
        }
        return ans;
    }
};
