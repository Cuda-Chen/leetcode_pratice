# O(n^2) solution
# current wrong

# @param {Integer[]} nums
# @param {Integer} k
# @return {Integer[]}
def max_sliding_window(nums, k)
    return [] if nums.empty?
    result = []
    
    nums[0..-k].each_with_index do |num, i|
        temp = num
        nums[(i + 1)...(i + k)].each do |num|
            temp = num if num > temp
        end
        
        result << temp
    end
    
    result
end
