// priority queue to trace maximum

class Solution {
public:
    long long maxKelements(vector<int>& A, int k) {
        priority_queue<int> q(begin(A), end(A));
        long long ans = 0LL;
        while(k--) {
            int a = q.top();
            q.pop();
            ans += a;
            a = (int)ceil((double)a / 3.0);
            q.push(a);
        }
        return ans;
    }
};
