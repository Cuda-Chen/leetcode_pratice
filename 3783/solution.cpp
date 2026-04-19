class Solution {
public:
    int mirrorDistance(int n) {
        int tmp = 0;
        int cpy = n;
        while(cpy) {
            tmp *= 10;
            tmp += cpy % 10;
            cpy /= 10;
        }
        return abs(tmp - n);
    }
};
