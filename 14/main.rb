# divide and conquer

# @param {String[]} strs
# @return {String}
def longest_common_prefix(strs)
    if strs.nil? || strs.size <= 0
        return ""
    end
    
    longest_common_prefix_helper strs, 0, strs.size - 1
end

def longest_common_prefix_helper(strs, left, right)
    if left == right
        strs[left]
    else
        mid = (left + right) / 2
        str1 = longest_common_prefix_helper strs, left, mid
        str2 = longest_common_prefix_helper strs, mid + 1, right
        common_prefix str1, str2 
    end
end

def common_prefix(str1, str2)
    minimum = [str1.size, str2.size].min
    result = ""
    
    0.upto(minimum) do |i|
        if str1[i] != str2[i]
            result = str1[0...i]
            return result
        end
    end
    
    result = str1[0...minimum]
    result
end
