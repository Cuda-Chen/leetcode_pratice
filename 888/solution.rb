# two sum variant
# Ruby Set

# @param {Integer[]} a
# @param {Integer[]} b
# @return {Integer[]}
def fair_candy_swap(a, b)
    sum1 = a.sum
    sum2 = b.sum
    diff = (sum1 - sum2) / 2
    s = Set.new(a)
    
    b.each do |x|
        target = x + diff
        return [target, x] if s.include? target
    end
        
    []
end
