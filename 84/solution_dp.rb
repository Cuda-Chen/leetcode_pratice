# DP

# @param {Integer[]} heights
# @return {Integer}
def largest_rectangle_area(heights)
    n, result = heights.size, 0
    
    n.times do |i|
        if i + 1 < n && heights[i] <= heights[i + 1]
            next
        end
        
        h = heights[i]
        i.downto(0) do |j|
            h = [h, heights[j]].min
            w = i - j + 1
            result = [result, h * w].max
        end
    end
    
    result
end
