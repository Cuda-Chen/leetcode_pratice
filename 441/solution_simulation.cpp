// simulation
// arithmetic sequence

class Solution {
public:
    int arrangeCoins(int n) {
        long remain_coins = n;
        long need_coins = 1;
        long ans = 0;
        for(;;) {
            if(remain_coins < need_coins)
                break;
            remain_coins -= need_coins;
            ans++;
            need_coins++;
        }
        return static_cast<int>(ans);
    }
};
