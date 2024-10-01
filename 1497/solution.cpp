class Solution {
public:
    bool canArrange(vector<int>& A, int k) {
        unordered_map<int, int> m; // {mod_val, freq}
        for(int a : A)
            m[((a % k) + k) % k]++;

        for(auto &[val, freq] : m) {
            printf("%d %d\n", val, freq);
            if(
                ((val == 0) && (freq % 2 == 0)) ||
                ((val == k - val) && (freq % 2 == 0))
            )
                continue;

            if(freq != m[k - val])
                return false;
        }
        return true;
    }
};
