class Solution {
public:
    int getCommon(vector<int>& A, vector<int>& B) {
        int idx1 = 0, idx2 = 0;
        int ans;
        while(idx1 < A.size() && idx2 < B.size()) {
            if(A[idx1] < B[idx2])
                idx1++;
            else if(A[idx1] > B[idx2])
                idx2++;
            else
                return A[idx1];
        }
        return -1;
    }
};
