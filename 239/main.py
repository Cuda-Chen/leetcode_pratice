# O(n^2) solution

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        if nums is None or n <= 0:
            return None
        result = []
        
        for i in range(n - k + 1):
            temp = -10000
            for j in range(i, i + k):
                if nums[j] > temp:
                    temp = nums[j]
                    
            result.append(temp)
                
        return result
