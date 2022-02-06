// https://www.cnblogs.com/grandyang/p/5085379.html
// monotonic stack

class Solution {
public:
    string smallestSubsequence(string s) {
        int m[256] = {0}, visit[256] = {0};
        string ans = "0";
        for(auto a : s) m[a]++;
        for(auto a : s) {
            m[a]--;
            if(visit[a]) continue;
            while(a < ans.back() && m[ans.back()]) {
                visit[ans.back()] = 0;
                ans.pop_back();
            }
            ans += a;
            visit[a] = 1;
        }
        return ans.substr(1);
    }
};
