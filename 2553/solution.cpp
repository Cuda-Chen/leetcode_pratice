class Solution {
public:
    vector<int> separateDigits(vector<int>& A) {
        vector<int> ans;
        for(int a : A) {
            vector<int> tmp;
            while(a) {
                tmp.push_back(a % 10);
                a /= 10;
            }
            ans.insert(ans.end(), tmp.rbegin(), tmp.rend());
        }
        return ans;
    }
};
