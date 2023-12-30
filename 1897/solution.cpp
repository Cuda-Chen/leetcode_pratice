class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> cnt(26);
        for(auto w : words) {
            for(char c : w)
                cnt[c - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(cnt[i] % n != 0)
                return false;
        }
        return true;
    }
};
