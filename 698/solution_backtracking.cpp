// backtracking

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1)
            return true;
        if(n < k)
            return false;
        int sum = accumulate(begin(nums), end(nums), 0);
        if(sum % k != 0)
            return false;
    
        int target = sum / k;
        vector<int> subset(k);
        vector<bool> visit(n);
        subset[0] = nums[n - 1];
        visit[n - 1] = true;

        return helper(nums, subset, visit,
        target, k, n, 0, n - 1);
    }

private:
    bool helper(vector<int> &nums, vector<int> &subset, vector<bool> &visit,
        int target, int k, int n, int l, int r) {
            if(subset[l] == target) {
                if(l == k - 2)
                    return true;
                return helper(nums, subset, visit,
        target, k, n, l + 1, n - 1);
            }
            for(int i = r; i >= 0; i--) {
                if(visit[i])
                    continue;
                int tmp = subset[l] + nums[i];
                if(tmp <= target) {
                    visit[i] = true;
                    subset[l] += nums[i];
                    bool next = helper(nums, subset, visit,
        target, k, n, l, i - 1);
                    visit[i] = false;
                    subset[l] -= nums[i];
                    if(next)
                        return true;
                }
            }
            return false;
        }
};
