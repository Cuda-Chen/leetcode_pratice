# DP
# https://leetcode.com/problems/count-the-repetitions/discuss/95398/c-solution-inspired-by-70664914-with-organized-explanation

# @param {String} s1
# @param {Integer} n1
# @param {String} s2
# @param {Integer} n2
# @return {Integer}
def get_max_repetitions(s1, n1, s2, n2)
    repeat_count = Array.new(n1 + 1, 0)
    next_index = Array.new(n1 + 1, 0)
    j = count = 0
    
    1.upto(n1) do |k|
        s1.size.times do |i|
            if s1[i] == s2[j]
                j += 1     
                if j == s2.size
                    j = 0
                    count += 1
                end
            end
        end
        
        repeat_count[k] = count
        next_index[k] = j
        k.times do |start|
            if next_index[start] == j
                prefix_count = repeat_count[start]
                pattern_count = (n1 - start) / (k - start) * (repeat_count[k] - prefix_count)
                suffix_count = repeat_count[start + (n1 - start) % (k - start)] - prefix_count
                return (prefix_count + pattern_count + suffix_count) / n2;
            end
        end
    end
    
    repeat_count[n1] / n2
end
