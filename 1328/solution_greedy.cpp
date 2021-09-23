// greedy
// For the first half of the string, replace the first non ‘a’ character to ‘a’.

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        string ans = palindrome;
        bool flag = false;
        if(n == 1) return "";
        for(int i = 0; i < n / 2; i++) {
            if(ans[i] != 'a') {
                ans[i] = 'a';
                flag = true;
                break;
            }
        }
        
        if(!flag)
            ans[n - 1] = 'b';
        
        return ans;
    }
};
