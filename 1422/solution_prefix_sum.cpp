// prefix sum

class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        int zeros = 0;
        int n = s.size();
        for(int i = 0; i < n; i++)
            ones += (s[i] - '0');

        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            char c = s[i];
            if(c == '0')
                zeros++;
            if(c == '1')
                ones--;
            ans = max(ans, zeros + ones);
        }
        return ans;
    }
};
