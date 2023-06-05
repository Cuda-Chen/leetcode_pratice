// math

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        sort(coordinates.begin(), coordinates.end());
        double inf = std::numeric_limits<double>::infinity();
        int delta_x = (coordinates[1][0] - coordinates[0][0]);
        int delta_y = (coordinates[1][1] - coordinates[0][1]);
        double m;
        m = (delta_x == 0) ? inf : (delta_y / delta_x);
        for(int i = 2; i < coordinates.size(); i++) {
            int dx = (coordinates[i][0] - coordinates[i - 1][0]);
            int dy = (coordinates[i][1] - coordinates[i - 1][1]);
            double tmp = (dx == 0) ? inf : (dy / dx);
            if(m != tmp)
                return false;
        }
        return true;
    }
};
