// hash table
// Use hash table to count the occurance of values.

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> counts;
        vector<int> ans;
        
        for(int num : nums) {
            if(counts.count(num))
                counts[num] += 1;
            else
                counts[num] = 1;
        }
        
        for(int num : nums) {
            if(counts[num] == 1)
                ans.emplace_back(num);
        }
        
        return ans;
    }
};
