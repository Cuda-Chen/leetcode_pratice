// https://zxi.mytechroad.com/blog/math/leetcode-313-super-ugly-number/
// DP (set)

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1) return 1;
        set<int> s{begin(primes), end(primes)};
        
        for(int i = 0; i < n - 2; i++) {
            auto it = begin(s);
            int t = *it;
            s.erase(it);
            for(int p : primes) {
                if(INT_MAX / t < p) continue;
                s.insert(t * p);
            }
        }
        
        return *begin(s);
    }
};
