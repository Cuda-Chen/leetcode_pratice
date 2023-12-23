#define SET_POS(d, y, x) \
    do { \
        if(d == 'N') \
            y++; \
        else if(d == 'E') \
            x++; \
        else if(d == 'S') \
            y--; \
        else if(d == 'W') \
            x--; \
    } while(0)

class Solution {
public:
    bool isPathCrossing(string path) {
        int y = 0, x = 0;
        set<pair<int, int>> s;
        s.insert({y, x});
        for(int i = 0; i < path.size(); i++) {
            SET_POS(path[i], y, x);
            if(s.count({y, x}) != 0)
                return true;
            s.insert({y, x});
        }
        return false;
    }
};
