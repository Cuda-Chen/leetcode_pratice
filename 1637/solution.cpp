class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& A) {
        sort(A.begin(), A.end(), [](const auto &a, const auto &b) {
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        int ans = 0;
        for(int i = 1; i < A.size(); i++) {
            int x1 = A[i - 1][0];
            int x2 = A[i][0];
            ans = max(ans, x2 - x1);
        }
        return ans;
    }
};
