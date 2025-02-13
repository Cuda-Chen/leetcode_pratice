// use log to prevent overflow

class Solution {
public:
    int minOperations(vector<int>& A, int k) {
        int ans = 0;
        using T = long;
        priority_queue<T, vector<T>, greater<T>> q{begin(A), end(A)};
        while(q.size() >= 2 && q.top() < k) {
            T x = q.top();
            q.pop();
            T y = q.top();
            q.pop();
            q.push({min(x, y) * 2L + max(x, y)});
            ans++;
        }
        return ans;
    }
};
