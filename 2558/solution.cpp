class Solution {
public:
    long long pickGifts(vector<int>& A, int k) {
        priority_queue<int> q(begin(A), end(A));
        for(int i = 0; i < k; i++) {
            int tmp = q.top();
            q.pop();
            tmp = sqrt(tmp);
            q.push(tmp);
        }

        long long ans = 0LL;
        while(!q.empty()) {
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};
