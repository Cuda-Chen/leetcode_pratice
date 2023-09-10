class Solution {
public:
    double findMaxAverage(vector<int>& A, int k) {
        int n = A.size();
        double ans = 0.0;
        int sum = 0;
        for(int i = 0; i < k; i++)
            sum += A[i];
        ans = (double)sum / k;
        for(int i = k; i < n; i++) {
            sum -= A[i - k];
            sum += A[i];
            ans = max(ans, (double)sum / k);
        }
        return ans;
    }
};
