// one pass hash table

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.size() <= 0) {
            return result;
        }
        
        unordered_map<int, int> hashTable;
        
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto iter = hashTable.find(complement);
            if(iter != hashTable.end()) {
                result.push_back(iter->second);
                result.push_back(i);
                break;
            } else {
                hashTable.insert(make_pair(nums[i], i));
            }
        }
        
        return result;
    }
};
