// https://zxi.mytechroad.com/blog/math/leetcode-204-count-primes/
// Sieve of Eratosthenes

class Solution {
public:
    int countPrimes(int n) {
        if(n < 3)
            return 0;
        vector<int> dp(n, 1);
        dp[0] = dp[1] = 0;
        for(int i = 2; i <= sqrt(n); i++) {
            if(!dp[i])
                continue;
            for(int j = i * i; j < n; j += i)
                dp[j] = 0;
        }
        return accumulate(begin(dp), end(dp), 0);
    }
};
