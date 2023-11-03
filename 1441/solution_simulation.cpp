class Solution {
public:
    vector<string> buildArray(vector<int>& A, int n) {
        int cur = 1;
        int idx = 0;
        vector<string> ans;
        while(idx < A.size()) {
            int a = A[idx];
            if(a == cur) {
                idx++;
                ans.push_back("Push");
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            cur++;
        }
        return ans;
    }
};
