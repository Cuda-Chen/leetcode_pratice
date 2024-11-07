class Solution {
public:
    int largestCombination(vector<int>& A) {
        vector<int> cnt(32); // count of each bit
        for(int a : A) {
            for(int i = 0; i < 32; i++)
                cnt[i] += (a >> i) & 1;
        }
        return *max_element(begin(cnt), end(cnt));
    }
};
