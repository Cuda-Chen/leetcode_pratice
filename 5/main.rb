# expand around center

# @param {String} s
# @return {String}
def longest_palindrome(s)
    n = s.size
    return "" if s.empty?
    
    left = right = 0
    n.times do |i|
        len1 = expand_around_center s, i, i
        len2 = expand_around_center s, i, i + 1
        len = [len1, len2].max
        
        if len > right - left
            left = i - (len - 1) / 2
            right = i + len / 2
        end
    end
    
    s[left..right]
end

def expand_around_center(s, left, right) 
    while left >= 0 && right < s.size && s[left] == s[right]
        left -= 1
        right += 1
    end
    
    right - left - 1
end
