class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum = accumulate(begin(chalk), end(chalk), 0L);
        k = (long)k % sum;
        int idx = 0;
        while(k >= chalk[idx]) {
            k -= chalk[idx];
            idx++;
        }
        return idx;
    }
};
