// BFS

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visit(begin(deadends), end(deadends));
        queue<string> q{{"0000"}};
        int steps = 0;

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto t = q.front();
                q.pop();
                if(visit.count(t))
                    continue;
                if(t == target)
                    return steps;
                visit.insert(t);
                for(int i = 0; i < 4; i++) {
                    for(int j : {-1, 1}) {
                        auto next = t;
                        next[i] = (next[i] - '0' + j + 10) % 10 + '0';
                        q.push(next);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
