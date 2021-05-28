// two pointers (TLE)
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        
        for(int i = 0; i < n; i++) {
            int j = i + 1;
            set<int> s;
            s.insert(nums[i]);
                
            for(; j < n; j++) {
                if(s.find(nums[j]) != s.end())
                    break;
                s.insert(nums[j]);
            }
            
            int temp = 0;
            for(int k = i; k <= j - 1; k++)
                temp += nums[k];
            
            result = max(result, temp);
        }
        
        return result;
    }
};
