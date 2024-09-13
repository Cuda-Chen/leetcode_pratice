// prefix sum

class Solution {
public:
    vector<int> xorQueries(vector<int>& A, vector<vector<int>>& queries) {
        int n = A.size();
        vector<int> pre(n), suf(n);
        pre[0] = A[0];
        for(int i = 1; i < n; i++)
            pre[i] = pre[i - 1] ^ A[i];
        suf[n - 1] = A[n - 1];
        for(int i = n - 2; i >= 0; i--)
            suf[i] = suf[i + 1] ^ A[i];

        vector<int> ans(queries.size());
        for(int q = 0; q < queries.size(); q++) {
            int s = queries[q][0];
            int e = queries[q][1];
            int a = pre[n - 1];
            if(s > 0)
                a ^= pre[s - 1];
            if(e < n - 1)
                a ^= suf[e + 1];
            ans[q] = a;
        }
        return ans;
    }
};
