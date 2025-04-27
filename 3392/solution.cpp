class Solution {
public:
    int countSubarrays(vector<int>& A) {
        int ans = 0;
        for(int i = 0; i < A.size() - 2; i++) {
            int a = A[i];
            int b = A[i + 1];
            int c = A[i + 2];
            if(2 * (a + c) == b)
                ans++;
        }
        return ans;
    }
};
