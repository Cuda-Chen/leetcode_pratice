# two pointers

def max(a, b)
    return a > b ? a : b
end

def min(a,b)
    return a < b ? a : b
end

# @param {Integer[]} height
# @return {Integer}
def max_area(height)
    result = 0
    left = 0
    right = height.size - 1
    
    while left < right
        result = max result, min(height[left], height[right]) * (right - left)
        
        if height[left] < height[right]
            left += 1
        else
            right -= 1
        end
    end

    result
end
