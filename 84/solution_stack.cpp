// monotonic stack

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int n = heights.size();
        int result = 0, i = 0;
        
        while(i < n) {
            if(s.empty() || heights[i] >= heights[s.top()]) {
                s.push(i);
                i++;
            } else {
                int h = heights[s.top()]; s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                result = max(result, h * w);
            }
        }
        
        return result;
    }
};
