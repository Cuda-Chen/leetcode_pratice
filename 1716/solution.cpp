class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        const int s = 28;
        int q = n / 7, r = n % 7; // whole weeks and day remains

        // sum of whole weeks' value
        ans += (28 * q);
        ans += (7 * q * (q - 1) / 2);

        // sum of day remains' value
        ans += (r * (r + 1) / 2);
        ans += (r * q);

        return ans;
    }
};
