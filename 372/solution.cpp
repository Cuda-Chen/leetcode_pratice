class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        int mod = 1337;

        function<int(int, int)> mypow = [&](int x, int y) {
            if(y == 0)
                return 1;

            x %= mod;
            if(y & 1)
                return (x * mypow(x, y - 1)) % mod;
            int sub = mypow(x, y >> 1);
            return (sub * sub) % mod;
        };

        a %= mod;
        for(int i : b)
            ans = mypow(ans, 10) * mypow(a, i) % mod;
        return ans;
    }
};
