// greedy

class Solution {
public:
    long long findMaximumScore(vector<int>& A) {
        if(A.size() == 1)
            return 0;

        long long ans = 0;
        int idx = 0, j = 0;
        int num = A[idx];
        for(j = 1; j < A.size(); j++) {
            if(A[j] > num) {
                ans += (j - idx) * (long long)num;
                idx = j;
                num = A[j];
            }
        }

        if(idx != A.size() - 1)
            ans += (A.size() - 1 - idx) * num;
        return ans;
    }
};
