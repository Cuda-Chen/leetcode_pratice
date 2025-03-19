class Solution {
public:
    int minOperations(vector<int>& A) {
        int n = A.size();
        int i = 0;
        int ans = 0;
        for(; i + 3 <= n; i++) {
            if(A[i])
                continue;

            for(int j = i; j < i + 3; j++)
                A[j] ^= 1;
            ans++;
        }

        for(; i < n; i++) {
            if(!A[i])
                return -1;
        }
        return ans;
    }
};
