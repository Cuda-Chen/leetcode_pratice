// divide and conquer

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty() || strs.size() <= 0) {
            return "";
        }
        
        return longestCommonPrefixHelper(strs, 0, strs.size() - 1);
    }

private:
    string longestCommonPrefixHelper(vector<string> &strs, int left, int right) {
        if(left == right) {
            return strs[left];
        } else {
            int mid = (left + right) / 2;
            string str1 = longestCommonPrefixHelper(strs, left, mid);
            string str2 = longestCommonPrefixHelper(strs, mid + 1, right);
            return commonPrefix(str1, str2);
        }
    }
    
    string commonPrefix(string str1, string str2) {
        int minimum = min(str1.length(), str2.length());
        string result;
        
        for(int i = 0; i < minimum; i++) {
            if(str1[i] != str2[i]) {
                result = str1.substr(0, i);
                return result;
            }
        }
        
        result = str1.substr(0, minimum);
        return result;
    }
};
