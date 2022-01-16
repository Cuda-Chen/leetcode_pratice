// https://www.cnblogs.com/grandyang/p/10759525.html
// priority queue

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size(), l = 0, r = n - 1;
        sort(A.begin(), A.end());
        priority_queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
            q.push({B[i], i});
        vector<int> ans(n);
        while(!q.empty()) {
            int val = q.top().first, idx = q.top().second;
            q.pop();
            ans[idx] = (A[r] <= val) ? A[l++] : A[r--];
        }
        return ans;
    }
};
