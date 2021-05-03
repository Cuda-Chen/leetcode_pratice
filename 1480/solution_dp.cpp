// DP

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        
        result[0] = nums[0]; // initial case
        for(int i = 1; i < n; i++) 
            result[i] = result[i - 1] + nums[i];
        
        return result;
    }
};
