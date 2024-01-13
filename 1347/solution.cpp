class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> s_cnt(26), t_cnt(26);
        for(char c : s)
            s_cnt[c - 'a']++;
        for(char c : t)
            t_cnt[c - 'a']++;

        int ans = 0;
        for(int i = 0; i < 26; i++) {
            if(s_cnt[i] > t_cnt[i])
                ans += abs(s_cnt[i] - t_cnt[i]);
        }
        return ans;
    }
};
