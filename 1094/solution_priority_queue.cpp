// https://www.cnblogs.com/grandyang/p/14610156.html
// "priority queue"

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> data;
        for(auto t : trips) {
            data.push_back({t[1], t[0]});
            data.push_back({t[2], -t[0]});
        }
        sort(begin(data), end(data));
        int cur = 0;
        for(auto a : data)
            if((cur += a[1]) > capacity) return false;
        return true;
    }
};
