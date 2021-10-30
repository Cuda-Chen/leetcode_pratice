// https://www.cnblogs.com/grandyang/p/7381633.html
// greedy

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });
        
        stack<vector<int>> s;
        for(auto pair : pairs) {
            if(s.empty()) {
                s.push(pair);
            } else {
                auto temp = s.top();
                if(temp[1] < pair[0])
                    s.push(pair);
            }
        }
        
        return s.size();
    }
};
