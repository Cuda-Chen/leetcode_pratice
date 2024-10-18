// backtracking

class Solution {
public:
    int countMaxOrSubsets(vector<int>& A) {
        int mx = std::accumulate(begin(A), end(A), 0, [](int cur, const auto &v) { return cur | v; });
        
        int ans = 0;
        vector<int> tmp;
        for(int i = 0; i < A.size(); i++) {
            tmp.push_back(A[i]);
            f(A, ans, mx, i, tmp);
            tmp.pop_back();
        }
        return ans;
    }

private:
    void f(
        vector<int> &A,
        int &ans,
        int target,
        int start,
        vector<int> &tmp
    ) {
        if(std::accumulate(begin(tmp), end(tmp), 0, [](int cur, const auto &v) { return cur | v; }) == target)
            ans++;

        for(int i = start + 1; i < A.size(); i++) {
            tmp.push_back(A[i]);
            f(A, ans, target, i, tmp);
            tmp.pop_back();
        }
    }
};
