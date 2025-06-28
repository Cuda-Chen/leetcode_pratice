// O(1) space

class Solution {
public:
    int trap(vector<int>& A) {
        int n = A.size();
        if(n == 1)
            return 0;

        int l = 0, r = n - 1;
        int maxL = A[l], maxR = A[r];
        int ans = 0;
        while(l < r) {
            if(maxL < maxR) {
                ans += maxL - A[l];
                maxL = max(maxL, A[++l]);
            } else {
                ans += maxR - A[r];
                maxR = max(maxR, A[--r]);
            }
        }
        return ans;
    }
};
