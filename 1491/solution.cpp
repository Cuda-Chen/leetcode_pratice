class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int mx = INT_MIN, mi = INT_MAX;
        for(int a : salary) {
            mx = max(mx, a);
            mi = min(mi, a);
        }
        return (double)(accumulate(begin(salary), end(salary), 0) - mx - mi) / (n - 2);
    }
};
