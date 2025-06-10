class Solution {
public:
    int maxDifference(string s) {
        vector<int> cnt(26);
        for(char c : s)
            cnt[c - 'a']++;
            
        int odd = 0; // largest odd frequency
        int even = INT_MAX; // smallest even frequency
        for(int i = 0; i < 26; i++) {
            if(cnt[i] == 0) // if not existed
                continue;

            if(cnt[i] % 2 == 1)
                odd = max(odd, cnt[i]);
            else
                even = min(even, cnt[i]);
        }

        return odd - even;
    }
};
