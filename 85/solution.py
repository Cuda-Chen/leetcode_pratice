# monotonic stack

class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return 0
        heights = [0] * len(matrix[0])
        result = 0
        
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                heights[j] = 0 if matrix[i][j] == '0' else (1 + heights[j])
            result = max(result, self.largestRectangleArea(heights))
        
        return result
    
    def largestRectangleArea(self, h: List[int]):
        n = len(h) + 1
        heights = [0] * n
        for i in range(n - 1):
            heights[i] = h[i]
        heights[-1] = 0
        s = []
        result, i = 0, 0
        
        while i < n:
            if not s or heights[i] >= heights[s[-1]]:
                s.append(i)
                i += 1
            else:
                h = heights[s[-1]]; s.pop()
                w = i if not s else i - s[-1] - 1
                result = max(result, h * w)
                
        return result
