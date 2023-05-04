// BFS

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& b) {
        int n = b.size(), m = b[0].size();
        string start;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                start += (b[i][j] + '0');
        }

        unordered_set<string> visit;
        queue<string> q{{start}};
        string goal = "123450";
        int steps = 0;
        vector<int> d{0, 1, 0, -1, 0};
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto t = q.front();
                q.pop();
                if(visit.count(t))
                    continue;
                if(t == goal)
                    return steps;
                visit.insert(t);
                int p = t.find('0');
                int y = p / m, x = p % m;
                for(int k = 0; k < 4; k++) {
                    int ty = y + d[k], tx = x + d[k + 1];
                    if(tx < 0 || ty < 0 || tx >= m || ty >= n)
                        continue;
                    int pp = ty * m + tx;
                    string next = t;
                    swap(next[p], next[pp]);
                    q.push(next);
                }
            }
            steps++;
        }
        return -1;
    }
};
