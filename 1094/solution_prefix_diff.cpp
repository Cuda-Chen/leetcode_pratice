// https://zxi.mytechroad.com/blog/heap/leetcode-1094-car-pooling/
// prefix difference

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> d(1001);
        for(auto t : trips) {
            d[t[1]] -= t[0];
            d[t[2]] += t[0];
        }
        for(int c : d)
            if((capacity += c) < 0) return false;
        return true;
    }
};
