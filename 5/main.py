# expand around center

class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if not s:
            return ""
        
        left, right = 0, 0
        for i in range(n):
            len1 = self.expandAroundCenter(s, i, i)
            len2 = self.expandAroundCenter(s, i, i + 1)
            length = max(len1, len2)
            
            if length > right - left:
                left = i - (length - 1) // 2
                right = i + length // 2
                
        return s[left:right + 1]
    
    def expandAroundCenter(self, s, left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
            
        return right - left - 1
        
