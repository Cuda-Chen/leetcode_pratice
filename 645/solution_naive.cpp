// Traverse array twice

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n + 1);
        for(int num : nums)
            cnt[num]++;
        vector<int> ans;
        for(int i = 1; i <= n; i++) {
            if(cnt[i] == 2)
                ans.push_back(i);
        }
        for(int i = 1; i <= n; i++) {
            if(cnt[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};
