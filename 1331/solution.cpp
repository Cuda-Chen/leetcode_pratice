class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& A) {
        unordered_set<int> m{begin(A), end(A)};
        vector<int> tmp;
        for(int e : m)
            tmp.push_back(e);
        ranges::sort(tmp);
        unordered_map<int, int> idx;
        for(int i = 0; i < tmp.size(); i++)
            idx[tmp[i]] = i;

        vector<int> ans(A.size());
        for(int i = 0; i < A.size(); i++)
            ans[i] = idx[A[i]] + 1;
        return ans;
    }
};
