# sliding window

class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        result = 0
        if k <= 1: return result
        product, left = 1, 0
        
        for right in range(len(nums)):
            product *= nums[right]
            while product >= k:
                product //= nums[left]
                left += 1
                
            result += right - left + 1
            
        return result
