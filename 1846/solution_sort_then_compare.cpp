// 1846. Maximum Element After Decreasing and Rearranging
// sort the compare

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& A) {
        if(A.size() == 1)
            return 1;

        sort(A.begin(), A.end());
        if(A[0] != 1)
            A[0] = 1;
        for(int i = 1; i < A.size(); i++) {
            if(abs(A[i] - A[i - 1]) > 1)
                A[i] = A[i - 1] + 1;
        }
        return A.back();       
    }
};
