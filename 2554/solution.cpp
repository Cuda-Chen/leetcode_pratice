class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> m(begin(banned), end(banned));
        int ans = 0;
        int tmp = 0;
        for(int i = 1; i <= n; i++) {
            if(m.count(i))
                continue;

            if(tmp + i > maxSum)
                break;
            tmp += i;
            ans++;
        }
        return ans;
    }
};
