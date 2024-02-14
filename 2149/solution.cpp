class Solution {
public:
    vector<int> rearrangeArray(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n);
        vector<int> odd, even;
        for(int a : A) {
            if(a > 0)
                odd.push_back(a);
            else
                even.push_back(a);
        }

        int idx = 0;
        for(int i = 0; i < n / 2; i++) {
            ans[idx] = odd[i];
            ans[idx + 1] = even[i];
            idx += 2;
        }
        return ans;
    }
};
