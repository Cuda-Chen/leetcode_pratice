# sliding window optimized (hash table)

# @param {String} s
# @return {Integer}
def length_of_longest_substring(s)
    if s.empty?
        return 0
    end
    
    map = {}
    result = 1
    left = -1
    s.size.times do |i|
        if map.has_key?(s[i]) && map[s[i]] > left
            left = map[s[i]]
        end
        
        result = [result, i - left].max
        map[s[i]] = i
    end
    
    result
end
