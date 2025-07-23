class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        string tmp;
        // Always remove the pattern with higher gain
        if(x > y) {
            tmp = f(s, "ab", ans, x);
            tmp = f(tmp, "ba", ans, y);
        } else {
            tmp = f(s, "ba", ans, y);
            tmp = f(tmp, "ab", ans, x);
        }
        return ans;
    }

private:
    string f(const string input, const string &p, int &acc, int score) {
        stack<char> s;
        for(int i = 0; i < input.size(); i++) {
            if(!s.empty() && input[i] == p[1] && s.top() == p[0]) {
                acc += score;
                s.pop();
                continue;
            }
            s.push(input[i]);
        }

        string ret;
        while(!s.empty()) {
            ret += s.top();
            s.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
