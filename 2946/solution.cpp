class Solution {
public:
    bool areSimilar(vector<vector<int>>& g, int k) {
        int m = g.size();
        int n = g[0].size();
        for(int i = 0; i < m; i++) {
            vector<int> row = g[i];
            vector<int> cc = g[i];
            int n = cc.size();
            for(int j = 0; j < n; j++) {
                int shift = k % n;
                cc[(j + (shift * (i & 1 ? 1 : -1)) + n) % n] = row[j];
            }
            if(row != cc)
                return false;
        }
        return true;
    }
};
