// index partition

class Solution {
public:
    vector<int> findErrorNums(vector<int>& A) {
        int dup;
        for(int &a : A) {
            int &tmp = A[abs(a) - 1];
            if(tmp < 0)
                dup = abs(a);
            else
                tmp *= -1;
        }
        for(int i = 0; i < A.size(); i++) {
            if(A[i] > 0)
                return {dup, i + 1};
        }
        throw;
    }
};
