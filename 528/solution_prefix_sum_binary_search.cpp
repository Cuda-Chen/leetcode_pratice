// https://zxi.mytechroad.com/blog/math/leetcode-528-random-pick-with-weight/
// prefix sum + binary search

class Solution {
public:
    Solution(vector<int>& w) : sums(std::move(w)) {
        partial_sum(begin(sums), end(sums), begin(sums));
    }
    
    int pickIndex() {
        int s = rand() % sums.back();
        return upper_bound(begin(sums), end(sums), s) - begin(sums);
    }
    
private:
    vector<int> sums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
