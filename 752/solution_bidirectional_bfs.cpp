// bidirectional BFS

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visit(begin(deadends), end(deadends));
        unordered_set<string> q1{{"0000"}}, q2{{target}};
        int steps = 0;

        while(!q1.empty() && !q2.empty()) {
            if(q1.size() > q2.size())
                swap(q1, q2);
            unordered_set<string> tmp;
            for(auto t : q1) {
                if(visit.count(t))
                    continue;
                if(q2.count(t))
                    return steps;
                visit.insert(t);
                for(int i = 0; i < 4; i++) {
                    for(int j : {-1, 1}) {
                        auto next = t;
                        next[i] = (next[i] - '0' + j + 10) % 10 + '0';
                        tmp.insert(next);
                    }
                }
            }
            steps++;
            q1 = q2;
            q2 = tmp;
        }
        return -1;
    }
};
