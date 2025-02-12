class Solution {
public:
    int maximumSum(vector<int>& A) {
        unordered_map<int, priority_queue<int>> m; // {sum of digits, {num (sort by decrease)}}
        for(int a : A) {
            int tmp = a;
            int sum = 0;
            while(tmp) {
                sum += tmp % 10;
                tmp /= 10;
            }

            m[sum].push(a);
        }

        int ans = -1;
        for(auto &[_, q] : m) {
            if(q.size() < 2)
                continue;
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            ans = max(ans, a + b);
        }
        return ans;
    }
};
