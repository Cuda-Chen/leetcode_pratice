struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int, int>, pair_hash> m;
        for(vector<int> &v : obstacles)
            m.insert({v[0], v[1]});

        int x = 0, y = 0;
        int ans = 0;
        vector<int> dirs{0, 1, 0, -1, 0};
        int d = 0;
        for(int c : commands) {
            if(c == -2) {
                d--;
                d = (d % 4 + 4) % 4;
            } else if(c == -1) {
                d++;
                d = (d % 4 + 4) % 4;
            } else {
                while(c) {
                    int xx = x + dirs[d];
                    int yy = y + dirs[d + 1];
                    if(m.count({xx, yy}))
                        break;
                    x = xx;
                    y = yy;
                    c--;
                }
                ans = max(ans, x * x + y * y);
            }
        }
        return ans;
    }
};
