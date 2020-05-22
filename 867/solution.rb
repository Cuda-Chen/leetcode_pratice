# @param {Integer[][]} a
# @return {Integer[][]}
def transpose(a)
    result = Array.new(a[0].size) {Array.new(a.size)}
    
    a.size.times do |i|
        a[0].size.times do |j|
            result[j][i] = a[i][j]
        end
    end
    
    result
end
