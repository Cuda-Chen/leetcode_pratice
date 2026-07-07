class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0;
        int cnt = 0; // index of digit
        while(n) {
            int d = n % 10;
            sum += d;
            if(d != 0) {
                for(int i = 0; i < cnt; i++)
                    d *= 10;
                x += d;
            }

            n /= 10;
            if(d != 0)
                cnt++;
        }
        //println("{} {}\n", sum, x);
        return sum * x;
    }
};
