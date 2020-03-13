# DP (bottom-up

# @param {String} s
# @return {Integer}
def count_palindromic_subsequences(s)
    n = s.size
    dp = Array.new(n) {Array.new(n, 0)}
    n.times do |i| 
        dp[i][i] = 1
    end
    
    (1..n).each do |len|
        (n - len).times do |i|
            j = i + len
            if s[i] == s[j]
                left, right = i + 1, j - 1
                dp[i][j] = dp[left][right] * 2
                left += 1 while left <= right && s[i] != s[left]
                right -= 1 while left <= right && s[i] != s[right]
                    
                if left == right
                    dp[i][j] += 1
                elsif left > right
                    dp[i][j] += 2
                else
                    dp[i][j] -= dp[left + 1][right - 1]
                end
            else
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]
            end
        end
    end
                
    dp[0][n - 1] % (10**9 + 7)
end
