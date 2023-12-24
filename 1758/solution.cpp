class Solution {
public:
    int minOperations(string s) {
        int ans = INT_MAX;
        int digit = 0;
        int tmp = 0;

        for(char c : s) {
            if((c - '0') != digit)
                tmp++;
            digit = (digit + 1) % 2;
        }
        ans = min(ans, tmp);

        digit = 1;
        tmp = 0;
        for(char c : s) {
            if((c - '0') != digit)
                tmp++;
            digit = (digit + 1) % 2;
        }
        ans = min(ans, tmp);

        return ans;
    }
};
