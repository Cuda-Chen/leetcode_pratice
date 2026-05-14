class Solution {
public:
    bool isGood(vector<int>& A) {
        int n = ranges::max(A);
        vector<int> cnt(n + 1);
        for(int a : A)
            cnt[a]++;

        for(int i = 1; i < n; i++) {
            if(cnt[i] != 1)
                return false;
        }
        if(cnt[n] != 2)
            return false;

        return true;
    }
};
