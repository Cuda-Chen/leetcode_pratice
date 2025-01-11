// math (referenced from LeetCode Hint in this problem)
// Count the # characters with odd counts then check
// whether it is less than or equal to k.
// Edge case: if s.length < k then just return false.

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k)
            return false;

        vector<int> cnt(26);
        for(char c : s)
            cnt[c - 'a']++;
        int odd_cnt = 0;
        for(int i = 0; i < 26; i++)
            odd_cnt += (cnt[i] % 2);
        return odd_cnt <= k;
    }
};
