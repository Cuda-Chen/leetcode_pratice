class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles >= numExchange) {
            int tmp = numBottles % numExchange;
            numBottles /= numExchange;
            ans += numBottles;
            numBottles += tmp;
        }
        return ans;
    }
};
