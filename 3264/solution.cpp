class Solution {
public:
    vector<int> getFinalState(vector<int>& A, int k, int multiplier) {
        using Pair = pair<int, int>;

        int n = A.size();
        priority_queue<Pair, vector<Pair>, greater<Pair>> q; // {num, idx}
        for(int i = 0; i < n; i++)
            q.emplace(A[i], i);

        for(int i = 0; i < k; i++) {
            auto [num, idx] = q.top();
            q.pop();
            q.emplace(num * multiplier, idx);
        }

        vector<int> ans(n);
        while(!q.empty()) {
            auto [num, idx] = q.top();
            q.pop();
            ans[idx] = num;
        }
        return ans;
    }
};
