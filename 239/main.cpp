class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        if(nums.empty() || n <= 0) {
            return result;
        }
        for(int i = 0; i <= n - k; i++) {
            int temp = INT_MIN;
            for(int j = i; j < i + k; j++) {
                if(nums[j] > temp) {
                    temp = nums[j];
                }
            }
            
            result.push_back(temp);
        }
        
        return result;
    }
};
