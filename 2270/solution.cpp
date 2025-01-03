// prefix sum

class Solution {
public:
    int waysToSplitArray(vector<int>& A) {
        long sum = accumulate(begin(A), end(A), 0L), tmp = 0L;
        int ans = 0;
        for(int i = 0; i < A.size() - 1; i++) {
            tmp += A[i];
            sum -= A[i];
            if(tmp >= sum)
                ans++;
        }
        return ans;
    }
};
