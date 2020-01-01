# one-pass

# @param {Integer[]} nums
# @return {Integer}
def first_missing_positive(nums)
    n = nums.size
    n.times do |i|
        while nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]
            rightIdx = nums[i] - 1
            nums[rightIdx], nums[i] = nums[i], nums[rightIdx]
        end
    end
    
    nums.each_with_index do |num, i|
        return i + 1 if num != i + 1
    end
    
    n + 1
end
