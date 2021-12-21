// https://leetcode-cn.com/problems/kth-smallest-instructions/solution/pai-lie-zu-he-by-euyvvl-iqvl/
// backtracking (TLE)

class Solution {
public:
    string kthSmallestPath(vector<int>& d, int k) {
        endR = d[0], endC = d[1];
        backtracking(0, 0, "");
        for(auto it = st.begin(); it != st.end(); it++) {
            if(k == 1) return *it;
            k--;
        }
        return "";
    }
    
private:
    int endR, endC;
    set<string> st;
    
    void backtracking(int startR, int startC, string s) {
        if(startR > endR || startC > endC) return;
        if(startR == endR && startC == endC) {
            st.insert(s);
            return;
        }
        backtracking(startR + 1, startC, s + "V");
        backtracking(startR, startC + 1, s + "H");
    }
};
