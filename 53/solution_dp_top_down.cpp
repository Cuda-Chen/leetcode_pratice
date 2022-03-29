// DP (top-down)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    
private:
    int helper(vector<int> &nums, int l, int r) {
        if(l >= r) return nums[l];
        int mid = l + (r - l) / 2;
        int lmax = helper(nums, l, mid - 1),
            rmax = helper(nums, mid + 1, r),
            mmax = nums[mid];
        int t = mmax;
        for(int i = mid - 1; i >= l; i--) {
            t += nums[i];
            mmax = max(mmax, t);
        }
        t = mmax;
        for(int i = mid + 1; i <= r; i++) {
            t += nums[i];
            mmax = max(mmax, t);
        }
        return max({lmax, rmax, mmax});
    }
};
