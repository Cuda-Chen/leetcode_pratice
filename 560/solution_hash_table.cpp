// https://zxi.mytechroad.com/blog/hashtable/leetcode-560-subarray-sum-equals-k/
// prefix sum + hash table

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> counts{{0, 1}};
        int cur_sum = 0, ans = 0;
        
        for(int num : nums) {
            cur_sum += num;
            ans += counts[cur_sum - k];
            counts[cur_sum]++;
        }
        
        return ans;
    }
};
