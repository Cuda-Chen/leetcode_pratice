# divide and conquer

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if strs == None or len(strs) <= 0:
            return ""
        
        return self.longestCommonPrefixHelper(strs, 0, len(strs) - 1)
    
    def longestCommonPrefixHelper(self, strs, left, right):
        if left == right:
            return strs[left]
        else:
            mid = (left + right) // 2
            str1 = self.longestCommonPrefixHelper(strs, left, mid)
            str2 = self.longestCommonPrefixHelper(strs, mid + 1, right)
            return self.commonPrefix(str1, str2)
        
    def commonPrefix(self, str1, str2):
        minimum = min(len(str1), len(str2))
        result = ""
        
        for i in range(minimum):
            if str1[i] != str2[i]:
                result = str1[:i]
                return result
            
        result = str1[:minimum]
        return result
        
