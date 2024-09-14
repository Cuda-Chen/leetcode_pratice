class Solution {
public:
    int longestSubarray(vector<int>& A) {
        int n = A.size();
        int l = 0, r = 0;
        int ans = 0, num = -1;
        while(r < n) {
            int tmp = A[l];
            while(r < n && A[r] == tmp)
                r++;

            if(tmp > num) {
                num = tmp;
                ans = r - l;
            } else if(tmp == num) {
                ans = max(ans, r - l);
            }
            
            l = r;
        }
        return ans;
    }
};
