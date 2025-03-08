// sliding window

class Solution {
public:
    int minimumRecolors(string s, int k) {
        int ans = INT_MAX;
        int tmp = 0; // store # white blocks
        auto isWhite = [&](int idx) -> bool {
            return s[idx] == 'W';
        };

        for(int i = 0; i < k; i++)
            tmp += isWhite(i);
        ans = min(ans, tmp);

        int n = s.size();
        for(int i = 1; i < n - k + 1; i++) {
            tmp -= isWhite(i - 1);
            tmp += isWhite(i + k - 1);
            ans = min(ans, tmp);
        }

        return ans;
    }
};
