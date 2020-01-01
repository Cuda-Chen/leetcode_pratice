# one-pass

# @param {Integer[]} nums
# @return {Integer}
def first_missing_positive(nums)
    n = nums.size
    nums.each_with_index do |num, i|
        while num > 0 && num <= n && num != nums[num - 1]
            nums[num - 1], nums[i] = num, nums[num - 1]
            num = nums[i]
        end
    end
    
    nums.each_with_index do |num, i|
        return i + 1 unless num == i + 1
    end
    
    n + 1
end
