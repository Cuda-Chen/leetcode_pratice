// TLE
// linear search
// Use set to store unique element.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0; // edge case
        
        set<int> s(nums.begin(), nums.end());
        vector<int> sorted(s.size());
        int i = 0;
        while(!s.empty()) {
            int a = *min_element(s.begin(), s.end());
            sorted[i] = a;
            i++;
            s.erase(a);
        }
        
        vector<int> consecutiveCount(sorted.size(), 1);
        if(sorted.size() == 1) return consecutiveCount[0]; // edge case
        for(int i = 1; i < sorted.size(); i++) {
            if(sorted[i] - sorted[i - 1] == 1)
                consecutiveCount[i] = 1 + consecutiveCount[i - 1];
        }
        
        return *max_element(consecutiveCount.begin(), consecutiveCount.end());
    }
};
