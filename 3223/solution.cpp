class Solution {
public:
    int minimumLength(string s) {
        vector<int> cnt(26);
        for(char c : s)
            cnt[c - 'a']++;

        int ans = 0;
        for(int e : cnt) {
            if(e == 0)
                continue;

            ans += (e % 2 == 0) ? 2 : 1;
        }
        return ans;
    }
};
