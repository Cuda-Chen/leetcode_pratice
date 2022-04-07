// priority queue
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(begin(stones), end(stones));
        while(q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            int tmp = abs(a - b);
            q.push(tmp);
        }
        return q.top();
    }
};
