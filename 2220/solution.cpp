class Solution {
public:
    int minBitFlips(int start, int goal) {
        int tmp = start ^ goal;
        return __builtin_popcount(tmp);
    }
};
