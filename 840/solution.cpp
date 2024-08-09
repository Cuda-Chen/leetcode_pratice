class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        int ans = 0;
        if(n < 3 || m < 3)
            return ans;

        for(int i = 1; i < n - 1; i++) {
            for(int j = 1; j < m - 1; j++) {
                unordered_set<int> seen;
                vector<int> v;
                for(int ii = i - 1; ii <= i + 1; ii++) {
                    for(int jj = j - 1; jj <= j + 1; jj++) {
                        int tmp = g[ii][jj];

                        seen.insert(tmp);
                        v.push_back(tmp);
                    }
                }

                bool continue_flag = false;

                if(seen.size() != v.size())
                    continue;
                for(int e : v) {
                    if(e < 1 || e > 9)
                        continue_flag = true;
                }
                if(continue_flag)
                    continue;

                int sum = v[0] + v[1] + v[2];
                // row
                for(int i = 3; i < 9; i += 3) {
                    int tmp = v[i] + v[i + 1] + v[i + 2];
                    if(tmp != sum)
                        continue_flag = true;
                }
                // col
                for(int i = 0; i < 3; i++) {
                    int tmp = v[i] + v[i + 3] + v[i + 6];
                    if(tmp != sum)
                        continue_flag = true;
                }
                // diag
                {
                    int tmp = v[0] + v[4] + v[8];
                    if(tmp != sum)
                        continue_flag = true;
                }
                {
                    int tmp = v[2] + v[4] + v[6];
                    if(tmp != sum)
                        continue_flag = true;
                }

                if(continue_flag)
                    continue;

                ans++;
            }
        }
        return ans;
    }
};
