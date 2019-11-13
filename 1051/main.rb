# @param {Integer[]} heights
# @return {Integer}
def height_checker(heights)
    n = heights.size
    rightPosition = Array.new(n)
    n.times do |i|
        rightPosition[i] = heights[i]
    end
    
    rightPosition.sort!
    
    result = 0
    n.times do |i|
        result += 1 if rightPosition[i] != heights[i]
    end
    
    result
end
