class Solution {
public:
    vector<int> intersection(vector<int>& A, vector<int>& B) {
        unordered_set<int> m;
        for(int a : A)
            m.insert(a);

        unordered_set<int> tmp;
        for(int b : B) {
            if(m.count(b))
                tmp.insert(b);
        }
        vector<int> ans(tmp.begin(), tmp.end());
        return ans;
    }
};
