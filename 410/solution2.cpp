// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-410-split-array-largest-sum/
// binary search

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long l = *max_element(nums.begin(), nums.end());
        long r = accumulate(nums.begin(), nums.end(), 0L) + 1;
        while(l < r) {
            long limit = l + (r - l) / 2;
            if(minGroups(nums, limit) > m)
                l = limit + 1;
            else
                r = limit;
        }
        return l;
    }
    
private:
    int minGroups(vector<int> &nums, long limit) {
        long sum = 0;
        int groups = 1;
        for(int num : nums) {
            if(sum + num > limit) {
                sum = num;
                groups++;
            } else {
                sum += num;
            }
        }
        return groups;
    }
};
