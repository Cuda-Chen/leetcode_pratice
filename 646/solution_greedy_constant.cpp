// https://www.cnblogs.com/grandyang/p/7381633.html
// greedy
// O(1) space

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });
        
        int ans = 0, end = INT_MIN;
        for(auto pair : pairs) {
            if(end < pair[0]) {
                ans++;
                end = pair[1];
            }
        }
        
        return ans;
    }
};
