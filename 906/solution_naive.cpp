// naive
// TLE in left = "38455498359" right = "999999999999999999"

class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        long long l = stoll(left);
        long long r = stoll(right);
        int counter = 0;
        for(long long i = (long long) sqrt(l); i * i <= r; i++) {
            // check if i is palindrom
            long long iReverse = reverseInteger(i);
            if(i == iReverse) {
                // check if i^2 is palindrome
                long long iSquare = i * i;
                long long iSquareReverse = reverseInteger(iSquare);
                if(iSquare == iSquareReverse) {
                    counter++;
                }
            }
        }
        return counter;
    }
    
    long long reverseInteger(long long n) {
        long long reverse = 0;
        while(n) {
            long long r = n % 10;
            reverse = reverse * 10 + r;
            n /= 10;
        }
        return reverse;
    }
};
