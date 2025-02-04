class Solution {
public:
    int maxAscendingSum(vector<int>& A) {
        int ans = 0;
        int tmp = 0;
        int prev = 0;
        for(int i = 0; i < A.size(); i++) {
            if((i == 0) || (prev < A[i]))
                tmp += A[i];
            else
                tmp = A[i];
            prev = A[i];
            ans = max(ans, tmp);
        }
        return ans;
    }
};
