class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        n = len(heights)
        rightPosition = [0] * n
        for i in range(n):
            rightPosition[i] = heights[i]
            
        rightPosition.sort()
        
        result = 0
        for i in range(n):
            if rightPosition[i] != heights[i]:
                result += 1
                
        return result
