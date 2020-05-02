# monotonic stack

# @param {Integer[]} heights
# @return {Integer}
def largest_rectangle_area(heights)
    heights.push 0
    n = heights.size
    s = []
    result = i = 0
    
    while i < n
        if s.empty? || heights[i] >= heights[s[-1]]
            s.push(i)
            i += 1
        else
            h = heights[s[-1]]; s.pop
            w = s.empty? ? i : i - s[-1] - 1
            result = [result, h * w].max
        end
    end
    
    result
end
