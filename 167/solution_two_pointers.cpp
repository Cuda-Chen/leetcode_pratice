// https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-167-two-sum-ii-input-array-is-sorted/
// two pointers

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while(i < j) {
            int sum = numbers[i] + numbers[j];
            if(sum == target)
                return {i + 1, j + 1};
            else if(sum > target)
                j--;
            else
                i++;
        }
        return {};
    }
};
