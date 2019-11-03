# one pass with hash table

# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
    n = nums.size
    result = Array.new
    hash_table = {}
    
    n.times do |i|
        complement = target - nums[i]
        if hash_table.has_key?(complement)
            result << hash_table[complement]
            result << i
        else
            hash_table[nums[i]] = i
        end
    end
    
    return result
end
