class Solution {
public:
    bool isOneBitCharacter(vector<int>& A) {
        int idx = 0;
        int n = A.size();
        while(idx < n - 1) {
            if(A[idx] == 1)
                idx += 2;
            else
                idx += 1;
        }
        return idx == n - 1 && A[idx] == 0;
    }
};
