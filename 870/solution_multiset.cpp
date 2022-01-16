// https://www.cnblogs.com/grandyang/p/10759525.html
// solution 1 (multiset)

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans;
        multiset<int> st(A.begin(), A.end());
        for(int i = 0; i < n; i++) {
            auto it = (*st.rbegin() <= B[i]) ? st.begin() : st.upper_bound(B[i]);
            ans.push_back(*it);
            st.erase(it);
        }
        return ans;
    }
};
