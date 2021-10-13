// monotonic stack

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> temp(n2);
        stack<int> s;
        for(int i = n2 - 1; i >= 0; i--) {
            while(!s.empty() && s.top() <= nums2[i])
                s.pop();
            temp[i] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }
        
        unordered_map<int, int> m;
        vector<int> ans(n1);
        for(int j = 0; j < n2; j++)
            m[nums2[j]] = temp[j];
        for(int k = 0; k < n1; k++)
            ans[k] = m[nums1[k]];
        
        return ans;
    }
};
