# provided by Tatsujin Chin
# @param {Integer[]} heights
# @return {Integer}
def height_checker(heights)
    heights.zip(heights.sort).count {|a, b| a != b}
end
