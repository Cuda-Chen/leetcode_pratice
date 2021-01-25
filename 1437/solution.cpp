// naive

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ones;
        for(int i = 0; i < n; i++) {
            if(nums[i])
                ones.push_back(i);
        }
        
        if(ones.size() <= 1) return true; 
        
        for(int i = 0; i < ones.size() - 1; i++) {
            if(ones[i + 1] - ones[i] - 1 < k)
                return false;
        }
        
        return true;
    }
};
