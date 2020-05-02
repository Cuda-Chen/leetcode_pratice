// DP

class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        int result = 0;
        
        for(int i = 0; i < n; i++) {
            if(i + 1 < n && heights[i] <= heights[i + 1]) {
                continue;
            }
            
            int h = heights[i], w;
            for(int j = i; j >= 0; j--) {
                h = Math.min(h, heights[j]);
                w = i - j + 1;
                result = Math.max(result, h * w);
            }
        }
        
        return result;
    }
}
