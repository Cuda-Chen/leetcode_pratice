class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        int cnt = 0; // count of negative numbers
        long long ans = 0;
        int mi = INT_MAX; // the smallest element after abs

        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                int tmp = mat[i][j];
                if(tmp < 0) {
                    cnt++;
                    tmp = abs(tmp);
                }
                mi = min(mi, tmp);
                ans += tmp;
            }
        }

        return (cnt % 2 == 0)
            ? ans
            : ans - (mi * 2);
    }
};
