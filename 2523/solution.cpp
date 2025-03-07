class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int u = 1e6;
        vector<bool> primes(u + 1, true);
        primes[0] = false;
        primes[1] = false;
        for(int p = 2; p * p <= u; p++) {
            if(primes[p]) {
                for(int i = p * p; i <= u; i += p)
                    primes[i] = false;
            }
        }

        vector<int> ans(2, -1); // store the temporary pair
        int prev;
        int diff = INT_MAX;
        for(int i = right; i >= left; i--) {
            if(!primes[i])
                continue;

            if(ans[1] == -1) {
                ans[1] = i;
                prev = i;
                continue;
            }

            int t = prev - i;
            if(t <= diff) {
                ans[0] = i;
                ans[1] = prev;
                diff = t;
            }
            prev = i;
        }

        if(ans[0] == -1 || ans[1] == -1)
            return {-1, -1};
        return ans;
    }
};
