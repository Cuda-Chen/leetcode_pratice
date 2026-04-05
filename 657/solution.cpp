class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, pair<int, int>> m{
            {'R', {0, 1}},
            {'L', {0, -1}},
            {'U', {1, 0}},
            {'D', {-1, 0}},
        };

        int x = 0, y = 0;
        for(char c : moves) {
            x += m[c].first;
            y += m[c].second;
        }
        return x == 0 && y == 0;
    }
};
