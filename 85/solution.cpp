// monotonic stack

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights;
        int result = 0;
        
        for(int i = 0; i < matrix.size(); i++) {
            heights.resize(matrix[i].size());
            for(int j = 0; j < matrix[i].size(); j++) {
                heights[j] = matrix[i][j] == '0' ? 0 : (1 + heights[j]);
            }
            result = max(result, largestRectangleArea(heights));
        }
        
        return result;
    }
    
private:
    int largestRectangleArea(vector<int> &heights) {
        heights.push_back(0);
        int n = heights.size();
        stack<int> s;
        int result = 0, i = 0;
        
        while(i < n) {
            if(s.empty() || heights[i] > heights[s.top()]) {
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
