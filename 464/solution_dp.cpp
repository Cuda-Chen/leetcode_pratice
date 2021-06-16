// https://zxi.mytechroad.com/blog/searching/leetcode-464-can-i-win/
// DP

class Solution {
public:
    bool canIWin(int M, int T) {
        int sum = M * (M + 1) / 2;
        if(sum < T) return false;
        if(T <= 0) return true;
        m = vector<char>(1 << M, 0);
        return canIWin(M, T, 0);
    }
    
private:
    vector<char> m;
    bool canIWin(int M, int T, int state) {
        if(T <= 0) return false;
        if(m[state]) return m[state] == 1;
        for(int i = 0; i < M; i++) {
            if(state & (1 << i)) continue;
            if(!canIWin(M, T - (i + 1), state | (1 << i)))
                return m[state] = 1;
        }
        m[state] = -1;
        return false;
    }
};
