class Solution {
public:
    int longestMonotonicSubarray(vector<int>& A) {
        int in = 0, de = 0; // max len of strictly increasing/decreasing
        int tmp = 0; // previous element
        int ans = 1;
        for(int i = 0; i < A.size(); i++) {
            if(i == 0) {
                in = de = 1;
                tmp = A[i];
                continue;
            }

            // increasing
            if(A[i] > tmp)
                in++;
            else
                in = 1;

            // decreasing
            if(A[i] < tmp)
                de++;
            else
                de = 1;

            tmp = A[i];
            ans = max({ans, in, de});
        }
        return ans;
    }
};
