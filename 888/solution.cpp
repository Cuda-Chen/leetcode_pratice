// https://leetcode.com/problems/fair-candy-swap/discuss/620291/Very-Basic-and-School-level-equations-Logic-Implemented-using-3-lines-cpp-STL
// two sum variant

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum1 = accumulate(A.begin(), A.end(), 0, plus<int>());
        int sum2 = accumulate(B.begin(), B.end(), 0, plus<int>());
        int diff = (sum1 - sum2) / 2;
        unordered_set<int> s(A.begin(), A.end());
        
        for(auto x: B) {
            int target = x + diff;
            if(s.count(target)) {
                return {target, x};
            }
        }
        
        return {};
    }
};
