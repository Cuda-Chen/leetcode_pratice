# binary search
# https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-4-median-of-two-sorted-arrays/
# INT_MIN and INT_MAX
N_BITS = 32
INT_MAX = 2**(N_BITS - 2) - 1
INT_MIN = -(INT_MAX) - 1

# @param {Integer[]} nums1
# @param {Integer[]} nums2
# @return {Float}
def find_median_sorted_arrays(nums1, nums2)
    n1, n2 = nums1.size, nums2.size
    return find_median_sorted_arrays nums2, nums1 if n1 > n2
    
    k = (n1 + n2 + 1) / 2
    left, right = 0, n1
    while left < right
        m1 = left + (right - left) / 2
        m2 = k - m1
        if nums1[m1] < nums2[m2 - 1]
            left = m1 + 1
        else
            right = m1
        end
    end
    
    m1 = left
    m2 = k - left
    
    c1 = [m1 <= 0 ? INT_MIN : nums1[m1 - 1],
          m2 <= 0 ? INT_MIN : nums2[m2 - 1]].max
    
    return c1 if (n1 + n2) % 2 == 1
    
    c2 = [m1 >= n1 ? INT_MAX : nums1[m1],
          m2 >= n2 ? INT_MAX : nums2[m2]].min
    
    (c1 + c2) / 2.0
end
