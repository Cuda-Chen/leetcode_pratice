# 0/1 knapsack problem

# @param {Integer} target
# @param {Integer} start_fuel
# @param {Integer[][]} stations
# @return {Integer}
def min_refuel_stops(target, start_fuel, stations)
    n = stations.size
    dp = Array.new(n + 1, start_fuel)
    
    0.upto(n - 1) do |i|
        (i + 1).downto(1) do |j|
            dp[j] = [dp[j], dp[j - 1] + stations[i][1]].max if dp[j - 1] >= stations[i][0]
        end
    end
    
    dp.size.times do |i|
        return i if dp[i] >= target
    end
    
    -1
end
