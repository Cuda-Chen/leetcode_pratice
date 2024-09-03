class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        int num = 0;

        // first transformation
        for(char c : s) {
            int tmp = c - 'a' + 1;
            while(tmp) {
                ans += tmp % 10;
                tmp /= 10;
            }
            num = ans;
        }

        for(int i = 1; i < k; i++) {
            ans = 0;
            while(num) {
                ans += num % 10;
                num /= 10;
            }
            num = ans;
        }
        return ans;
    }
};
