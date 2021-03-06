# recursive
# @param {String} s
# @param {String} p
# @return {Boolean}
def is_match(s, p)
      return s.empty? if p.empty?
    
  first_match = !s.empty? && (p[0] == s[0] || p[0] == '.')
    
  if p.size >= 2 && p[1] == '*'
      is_match(s, p[2..-1]) ||
             first_match && is_match(s[1..-1], p)
  else
      first_match && is_match(s[1..-1], p[1..-1])
  end
end
