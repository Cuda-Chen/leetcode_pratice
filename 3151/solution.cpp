class Solution {
public:
    bool isArraySpecial(vector<int>& A) {
        int n = A.size();
        for(int i = 1; i < n; i++) {
            int j = i - 1;
            if(((A[i] ^ A[j]) % 2) == 0)
                return false;
        }
        return true;
    }
};
