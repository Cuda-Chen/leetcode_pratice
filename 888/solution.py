# two sum variant

class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        sum1 = sum(A)
        sum2 = sum(B)
        diff = (sum1 - sum2) // 2
        s = set(A)
        
        for x in B:
            target = x + diff
            if target in s:
                return [target, x]
            
        return []
