# O(n^2) solution
# current wrong

# @param {Integer[]} nums
# @param {Integer} k
# @return {Integer[]}
def max_sliding_window(nums, k)
    n = nums.size
    return nil if nums == nil || n <= 0
    result = []
    
    n.times do |i|
        temp = -10000
        for j in i...(i + k)
            if nums[j] > temp
                temp = nums[j]
            end
        end
        
        result.push(temp)
    end
    
    result
end
