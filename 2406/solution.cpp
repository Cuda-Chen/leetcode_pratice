class Solution {
public:
    int minGroups(vector<vector<int>>& A) {
        ranges::sort(A);

        int ans = 0;
        priority_queue<int, vector<int>, greater<>> q; // end time
        for(auto a : A) {
            int s = a[0];
            int e = a[1];
            if(q.empty() || q.top() >= s)
                ans++;
            else
                q.pop();
            q.push(e);
        }
        return ans;
    }
};
