# DP
# https://leetcode.com/problems/count-the-repetitions/discuss/95398/c-solution-inspired-by-70664914-with-organized-explanation


class Solution:
    def getMaxRepetitions(self, s1: str, n1: int, s2: str, n2: int) -> int:
        repeatCount = [0] * (n1 + 1)
        nextIndex = [0] * (n1 + 1)
        j = count = 0
        
        for k in range(1, n1 + 1):
            for i in range(len(s1)):
                if s1[i] == s2[j]:
                    j += 1
                    if j == len(s2):
                        j = 0
                        count += 1
                        
            repeatCount[k] = count
            nextIndex[k] = j
            for start in range(k):
                if nextIndex[start] == j:
                    prefixCount = repeatCount[start]
                    patternCount = (n1 - start) // (k - start) * (repeatCount[k] - prefixCount)
                    suffixCount = repeatCount[start + (n1 - start) % (k - start)] - prefixCount
                    return (prefixCount + patternCount + suffixCount) // n2
                
        return repeatCount[n1] // n2
        
