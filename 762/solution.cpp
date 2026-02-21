class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> p{2, 3, 5, 7, 11, 13, 17, 19}; // primes, up to 19 set bits at the input value is at most 10^6
        int ans = 0;
        for(int i = left; i <= right; i++) {
            if(p.count(__builtin_popcount(i)))
                ans++;
        }
        return ans;
    }
};
