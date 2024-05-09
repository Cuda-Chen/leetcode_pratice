class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& A) {
        int n = A.size();
        vector<pair<int, int>> tmp;
        for(int i = 0; i < n; i++)
            tmp.push_back(make_pair(A[i], i));

        ranges::sort(tmp);

        vector<string> ans(n);
        for(int i = 0; i < n; i++) {
            auto &[_, idx] = tmp[i];
            string s;
            if(i == n - 1)
                s = "Gold Medal";
            else if(i == n - 2)
                s = "Silver Medal";
            else if(i == n - 3)
                s = "Bronze Medal";
            else
                s = to_string(n - i);
            ans[idx] = s;
        }
        return ans;
    }
};
