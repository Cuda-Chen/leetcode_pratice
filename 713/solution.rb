# sliding window

# @param {Integer[]} nums
# @param {Integer} k
# @return {Integer}
def num_subarray_product_less_than_k(nums, k)
    result = 0
    return result if k <= 1
    product, left = 1, 0
    
    nums.size.times do |right|
        product *= nums[right]
        while product >= k
            product /= nums[left]
            left += 1
        end
        
        result += right - left + 1
    end
    
    result
end
