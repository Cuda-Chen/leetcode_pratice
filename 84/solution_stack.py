# monotonic stack

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        result = 0
        s = []
        heights.append(0)
        n = len(heights)
        i = 0
        
        while i < n:
            if not s or heights[i] >= heights[s[-1]]:
                s.append(i)
                i += 1
            else:
                h = heights[s[-1]]; s.pop()
                w = i if not s else i - s[-1] - 1
                result = max(result, h * w)
        
        return result
