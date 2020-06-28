// monotonic stack

class Solution {
    public int maximalRectangle(char[][] matrix) {
        if(matrix.length <= 0 || matrix[0].length <= 0) {
            return 0;
        }
        int[] heights = new int[matrix[0].length];
        int result = 0;
        
        for(int i = 0; i < matrix.length; i++) {
            for(int j = 0; j < matrix[i].length; j++) {
                heights[j] = matrix[i][j] == '0' ? 0 : (1 + heights[j]);
            }
            result = Math.max(result, largestRectangleArea(heights));
        }
        
        return result;
    }
    
    private int largestRectangleArea(int[] h) {
        int n = h.length + 1;
        int[] heights = new int[n];
        for(int i = 0; i < n - 1; i++) {
            heights[i] = h[i];
        }
        heights[n - 1] = 0;
        Stack<Integer> s = new Stack<Integer>();
        int i = 0, result = 0;
        
        while(i < n) {
            if(s.empty() || heights[i] > heights[s.peek()]) {
                s.push(i);
                i++;
            } else {
                int height = heights[s.peek()]; s.pop();
                int w = s.empty() ? i : i - s.peek() - 1;
                result = Math.max(result, height * w);
            }
        }
        
        return result;
    }
}
