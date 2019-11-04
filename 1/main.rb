# one pass with hash table

# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
    n = nums.size
    result = Array.new
    hash_table = {}
    
    nums.each_with_index do |n, i|
        complement = target - nums[i]
        return hash_table[complement], i if hash_table.has_key? complement
            
        hash_table[nums[i]] = i
        end
    end
    
    result
end
