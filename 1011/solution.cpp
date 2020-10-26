// https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-1011-capacity-to-ship-packages-within-d-days/
// binary search

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0) + 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            int t = 0, d = 1;
            for(auto w : weights) {
                if((t += w) > mid) {
                    t = w;
                    d++;
                }
            }
            if(d <= D) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
