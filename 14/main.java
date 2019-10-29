// divide and conquer

class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs == null || strs.length <= 0) {
            return "";
        }
        
        return longestCommonPrefixHelper(strs, 0, strs.length - 1);
    }
    
    private String longestCommonPrefixHelper(String[] strs, int left, int right) {
        if(left == right) {
            return strs[left];
        } else {
            int mid = (left + right) / 2;
            String str1 = longestCommonPrefixHelper(strs, left, mid);
            String str2 = longestCommonPrefixHelper(strs, mid + 1, right);
            return commonPrefix(str1, str2);
        }
    }
    
    private String commonPrefix(String str1, String str2) {
        int minimum = Math.min(str1.length(), str2.length());
        String result;
        
        for(int i = 0; i < minimum; i++) {
            if(str1.charAt(i) != str2.charAt(i)) {
                result = str1.substring(0, i);
                return result;
            }
        }
        
        result = str1.substring(0, minimum);
        return result;
    }
}
