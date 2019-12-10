# sliding window optimized (hash table)

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n, result = len(s), 0
        if s is None:
            return result
        hashMap = {}
        i = 0
        
        for j in range(n):
            if s[j] in hashMap:
                i = max(i, hashMap[s[j]])
            result = max(result, j - i + 1)
            hashMap[s[j]] = j + 1
            
        return result
