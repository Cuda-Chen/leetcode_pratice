// naive 

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> odds, evens;
        for(auto num : nums) {
            if(num % 2 == 0)
                evens.emplace_back(num);
            else
                odds.emplace_back(num);
        }
        
        vector<int> ans;
        int cnt = 0;
        while(cnt < n) {
            if(cnt % 2 == 0) {
                ans.emplace_back(evens.back());
                evens.pop_back();
            } else {
                ans.emplace_back(odds.back());
                odds.pop_back();
            }
            cnt++;
        }
        
        return ans;
    }
};
