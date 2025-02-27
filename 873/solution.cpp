// Hash table record index,
// then find whether the target exists in hash table.

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        unordered_map<int, int> m; // {num, idx}
        for(int i = 0; i < n; i++)
            m[A[i]] = i;
        int mx = A.back();
        int ans = 0;
        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                int f1 = A[i];
                int f2 = A[j];
                int tmp = f1 + f2;
                if(!m.count(tmp))
                    continue;

                int cnt = 3;
                while(tmp <= mx) {
                    f1 = f2;
                    f2 = tmp;
                    tmp = f1 + f2;
                    if(!m.count(tmp))
                        break;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
