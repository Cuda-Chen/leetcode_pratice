# binary search
# https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-4-median-of-two-sorted-arrays/
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n1, n2 = len(nums1), len(nums2)
        if n1 > n2:
            return self.findMedianSortedArrays(nums2, nums1)
        
        k = (n1 + n2 + 1) // 2
        left, right = 0, n1
        while left < right:
            m1 = left + (right - left) // 2
            m2 = k - m1
            if nums1[m1] < nums2[m2 - 1]:
                left = m1 + 1
            else:
                right = m1
                
        m1 = left
        m2 = k - left
        
        c1 = max(float('-inf') if m1 <= 0 else nums1[m1 - 1],
                 float('-inf') if m2 <= 0 else nums2[m2 - 1])
        
        if (n1 + n2) % 2 == 1:
            return c1
        
        c2 = min(float('inf') if m1 >= n1 else nums1[m1],
                 float('inf') if m2 >= n2 else nums2[m2])
        
        return (c1 + c2) / 2.0
