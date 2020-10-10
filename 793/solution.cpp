// https://zxi.mytechroad.com/blog/math/leetcode-793-preimage-size-of-factorial-zeroes-function/
// math + binary search
// int -> long long
// also the upper bound, while Tatsujin uses lower bound

class Solution {
public:
    int preimageSizeFZF(int K) {
        return (int) (g(K) - g(K - 1));
    }
    
private:
    long long g(int K) {
        long long l = 0;
        long long r = 4000000000000000;
        while(l < r) {
            long long mid = l + (r - l) / 2;
            long long zeros = numZeros(mid);
            if(zeros <= K) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    
    long long numZeros(long long n) {
        return n < 5 ? 0 : (n / 5 + numZeros(n / 5));
    }
};
