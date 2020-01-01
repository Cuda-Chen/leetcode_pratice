# one-pass

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while nums[i] > 0 and nums[i] <= n and nums[i] != nums[nums[i] - 1]:
                rightIdx = nums[i] - 1
                nums[rightIdx], nums[i] = nums[i], nums[rightIdx]
                
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
            
        return n + 1
        
