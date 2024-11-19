class Solution {
public:
    long long maximumSubarraySum(vector<int>& A, int k) {
        int n = A.size();
        unordered_map<int, int> m; // {num, cnt}
        unordered_set<int> dup; // record the duplicates
        long long tmp = 0;
        for(int i = 0; i < k; i++) {
            m[A[i]]++;
            tmp += A[i];
            if(m[A[i]] > 1)
                dup.insert(A[i]);
        }
        long long ans = 0;
        if(dup.size() == 0)
            ans = max(ans, tmp);

        for(int i = 1; i + k - 1 < n; i++) {
            int leave = A[i - 1];
            m[leave]--;
            tmp -= leave;
            if(m[leave] <= 1)
                dup.erase(leave);

            int arrive = A[i + k - 1];
            m[arrive]++;
            tmp += arrive;
            if(m[arrive] > 1)
                dup.insert(arrive);

            if(dup.size() == 0)
                ans = max(ans, tmp);
        }

        return ans;
    }
};
