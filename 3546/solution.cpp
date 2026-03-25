class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        vector<long> r(m);
        for(int i = 0; i < m; i++) {
            long tmp = 0;
            for(int j = 0; j < n; j++)
                tmp += g[i][j];
            r[i] = (i == 0 ? 0 : r[i - 1]) + tmp;
        }
        long sum = r[m - 1];
        for(int i = 0; i < m - 1; i++) {
            if(r[i] == (sum - r[i]))
                return true;
        }

        vector<long> c(n);
        for(int j = 0; j < n; j++) {
            long tmp = 0;
            for(int i = 0; i < m; i++) 
                tmp += g[i][j];
            c[j] = (j == 0 ? 0 : c[j - 1]) + tmp;
        }
        sum = c[n - 1];
        for(int j = 0; j < n - 1; j++) {
            if(c[j] == (sum - c[j]))
                return true;
        }
        
        return false;
    }
};
