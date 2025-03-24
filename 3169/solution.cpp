class Solution {
public:
    int countDays(int days, vector<vector<int>>& A) {
        ranges::sort(A);
        // merge
        vector<vector<int>> tmp;
        tmp.push_back(A[0]);
        for(int i = 1; i < A.size(); i++) {
            if(A[i][0] <= tmp.back()[1])
                tmp.back()[1] = max(A[i][1], tmp.back()[1]);
            else
                tmp.push_back(A[i]);
        }

        // count empties
        int e = tmp[0][1];
        int ans = (tmp[0][0] - 1);
        for(int i = 1; i < tmp.size(); i++) {
            ans += (tmp[i][0] - e) - 1;
            e = tmp[i][1];
        }
        ans += (days - e);
        return ans;
    }
};
