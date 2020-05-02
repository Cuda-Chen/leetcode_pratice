// DP

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int result = 0;
        
        for(int i = 0; i < n; i++) {
            if(i + 1 < n && heights[i] <= heights[i + 1]) {
                continue;
            }
            
            int h = heights[i];
            for(int j = i; j >= 0; j--) {
                h = min(h, heights[j]);
                int w = i - j + 1;
                result = max(result, h * w);
            }
        }
        
        return result;
    }
};
