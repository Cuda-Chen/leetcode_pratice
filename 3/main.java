// sliding window optimized (hash table)

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), result = 0;
        if(s == null) {
            return result;
        }
        Map<Character, Integer> map = new HashMap<>();
        
        for(int j = 0, i = 0; j < n; j++) {
            if(map.containsKey(s.charAt(j))) {
                i = Math.max(i, map.get(s.charAt(j)));
            }
            result = Math.max(result, j - i + 1);
            map.put(s.charAt(j), j + 1);
        }
        
        return result;
    }
}
