# one pass with hash table

# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
    hash_table = {}
    
    nums.each_with_index do |num, i|
        complement = target - num
        return hash_table[complement], i if hash_table.has_key? complement

        hash_table[num] = i
    end
end
