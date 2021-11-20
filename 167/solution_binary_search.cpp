// https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-167-two-sum-ii-input-array-is-sorted/
// binary search

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i = 0; i < n; i++) {
            int t = target - numbers[i];
            int l = i + 1, r = n;
            while(l < r) {
                int mid = l + (r - l) / 2;
                if(t == numbers[mid])
                    return {i + 1, mid + 1};
                else if(t > numbers[mid])
                    l = mid + 1;
                else
                    r = mid;
            }
        }
        return {};
    }
};
