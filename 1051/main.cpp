class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        int rightPosition[n];
        
        for(int i = 0; i < n; i++) {
            rightPosition[i] = heights[i];
        }
        
        sort(rightPosition, rightPosition + n);
        
        int result = 0;
        for(int i = 0; i < n; i++) {
            if(heights[i] != rightPosition[i]) {
                result++;
            }
        }
        
        return result;
    }
};
