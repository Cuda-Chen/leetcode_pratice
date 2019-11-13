class Solution {
    public int heightChecker(int[] heights) {
        int n = heights.length;
        int[] rightPosition = new int[n];
        for(int i = 0; i < n; i++) {
            rightPosition[i] = heights[i];
        }
        
        Arrays.sort(rightPosition);
        
        int result = 0;
        for(int i = 0; i < n; i++) {
            if(rightPosition[i] != heights[i]) {
                result++;
            }
        }
        
        return result;
    }
}
