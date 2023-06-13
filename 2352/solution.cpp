// hash map

class Solution {
public:
    int equalPairs(vector<vector<int>>& g) {
        map<vector<int>, int> mr;
        int n = g.size();
        for(int i = 0; i < n; i++)
            mr[g[i]]++;

        map<vector<int>, int> mc;
        vector<int> tmp(n);
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < n; i++)
                tmp[i] = g[i][j];
            mc[tmp]++;
        }
        int ans = 0;
        for(auto kv : mr) {
            if(mc.count(kv.first))
                ans += (kv.second * mc[kv.first]);
        }
        return ans;
    }
};
