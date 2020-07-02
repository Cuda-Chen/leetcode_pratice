# monotonic stack

# @param {Character[][]} matrix
# @return {Integer}
def maximal_rectangle(matrix)
    return 0 if matrix.size <= 0 || matrix[0].size <= 0
    heights = Array.new(matrix[0].size, 0)
    result = 0
    
    matrix.size.times do |i|
        matrix[i].size.times do |j|
            heights[j] = matrix[i][j] == '0' ? 0 : (1 + heights[j])
        end
        result = [result, largest_rectangle_area(heights)].max
    end
    
    result
end

def largest_rectangle_area(h)
    n = h.size + 1
    heights = Array.new(n, 0)
    (n - 1).times do |i|
        heights[i] = h[i]
    end
    i = result = 0
    stack = []
    
    while i < n
        if stack.empty? || heights[i] > heights[stack[-1]]
            stack.push(i)
            i += 1
        else
            height = heights[stack[-1]]; stack.pop
            width = stack.empty? ? i : i - stack[-1] - 1
            result = [result, height * width].max
        end
    end
    
    result
end
