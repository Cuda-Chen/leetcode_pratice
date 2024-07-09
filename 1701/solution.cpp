class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& A) {
        int n = A.size();
        long ans = 0;
        int c = 1; // chef done time
        for(vector<int> &a : A) {
            int arrive = a[0];
            int t = a[1];

            if(arrive >= c)
                c = arrive;
            c += t;

            ans += (c - arrive);
        }
        return (double)ans / n;
    }
};
