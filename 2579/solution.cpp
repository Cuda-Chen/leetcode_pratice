class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        for(int i = 2; i <= n; i++)
            ans += (i * 4) - 4;
        return ans;
    }
};
