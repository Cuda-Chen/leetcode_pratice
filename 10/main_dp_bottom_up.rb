# DP (bottom-up)

# @param {String} s
# @param {String} p
# @return {Boolean}
def is_match(s, p)
    m, n = s.size, p.size
    dp = Array.new(m + 1) {Array.new(n + 1, false)}
    dp[0][0] = true
    
    0.upto(m) do |i|
        1.upto(n) do |j|
            if p[j - 1] == '*'
                dp[i][j] = dp[i][j - 2] || (i > 0 && dp[i - 1][j] && (p[j - 2] == s[i - 1] || p[j - 2] == '.'))
            else
                dp[i][j] = i > 0 && dp[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.')
            end
        end
    end
    
    dp[m][n]
end
