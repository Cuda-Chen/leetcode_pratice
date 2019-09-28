# one pass hash table
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result = []
        if(len(nums) <= 0):
            return result
        
        print("foo")
        hashTable = {}
        for i, num in enumerate(nums):
            if target - num in hashTable:
                result.append(hashTable[target - num])
                result.append(i)
            else:
                hashTable[num] = i
                
        return result
