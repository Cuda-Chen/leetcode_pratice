// https://zxi.mytechroad.com/blog/string/leetcode-553-optimal-division/
// math
// for X1/X2/X3/.../Xn, X1/(X2/X3/.../Xn) > X1/X2/(X3/.../Xn) > X1/X2/X3/(.../Xn)
// X1/(X2/X3/.../Xn)
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        string ans = to_string(nums[0]);
        if(n == 1) return ans;
        else if(n == 2) return ans + "/" + to_string(nums[1]);
        
        ans += "/(" + to_string(nums[1]);
        for(int i = 2; i < n; i++)
            ans += "/" + to_string(nums[i]);
        ans += ")";
        
        return ans;
    }
};
