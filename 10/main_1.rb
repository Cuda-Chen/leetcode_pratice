# iterative
#
# # @param {String} s
# # @param {String} p
# # @return {Boolean}
def is_match(s, p)
   s_len = s.size + 1
   p_len = p.size + 1
    
   dp = Array.new(p_len) {Array.new(s_len, false)}
   dp[0][0] = true
    
   (2...p_len).each do |i|
       dp[i][0] = p[i - 1] == '*' && dp[i - 2][0]
   end
    
   (1...p_len).each do |i|
       (1...s_len).each do |j|
           dp[i][j] = if p[i - 1] == '*' 
               dp[i - 2][j] || ((dp[i - 2][j - 1] || dp[i][j - 1]) && (p[i - 2] == '.' || p[i - 2] == s[j - 1]))
           else
               dp[i - 1][j - 1] && (p[i - 1] == '.' || p[i - 1] == s[j - 1])
           end
       end
   end
    
  return dp[p.size][s.size]
end
