# iterative
#
# # @param {String} s
# # @param {String} p
# # @return {Boolean}
def is_match(s, p)
  s_len = s.length() + 1
  p_len = p.length() + 1
    
  dp = Array.new(p_len) {Array.new(s_len, false)}
  dp[0][0] = true
  
  1.upto(p_len - 1) do |i|
      dp[i][0] = i > 1 && p[i - 1] == '*' && dp[i - 2][0] ? true : false
  end
  
  1.upto(p_len - 1) do |i|
      1.upto(s_len - 1) do |j|
          if p[i - 1] != '*' 
              dp[i][j] = dp[i - 1][j - 1] && (p[i - 1] == '.' || p[i - 1] == s[j - 1])
          else
              dp[i][j] = dp[i - 2][j] || ((dp[i - 2][j - 1] || dp[i][j - 1]) && (p[i - 2] == '.' || p[i - 2] == s[j - 1]))
          end
      end
  end
    
  return dp[p_len - 1][s_len - 1]
end
