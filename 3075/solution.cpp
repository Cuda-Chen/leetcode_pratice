// heap

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> q;
        for(int h : happiness)
            q.push(h);

        long long ans = 0;
        int cnt = 0;
        while(k--) {
            int t = q.top();
            q.pop();
            t -= cnt;
            ans += (t > 0) ? t : 0;
            cnt++;
        }
        return ans;
    }
};
