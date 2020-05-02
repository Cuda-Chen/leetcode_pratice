# DP

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n, result = len(heights), 0
        
        for i in range(n):
            if i + 1 < n and heights[i] <= heights[i + 1]:
                continue
            else:
                h = heights[i]
                for j in range(i, -1, -1):
                    h = min(h, heights[j])
                    w = i - j + 1
                    result = max(result, h * w)
                    
        return result
        
