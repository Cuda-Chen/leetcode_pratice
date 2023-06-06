// sorting
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& A) {
        int n = A.size();
        sort(A.begin(), A.end());
        int diff = A[1] - A[0];
        bool flag = true;
        for(int i = 2; i < n; i++) {
            if(diff != A[i] - A[i - 1]) {
                flag = false;
                break;
            }
        }
        if(flag)
            return true;
        sort(A.rbegin(), A.rend());
        diff = A[1] - A[0];
        flag = true;
        for(int i = 2; i < n; i++) {
            if(diff != A[i] - A[i - 1]) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};
