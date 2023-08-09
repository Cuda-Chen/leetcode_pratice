class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        if(m.count(s))
            return m[s];

        vector<int> tmp;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c == '+' || c == '-' || c == '*') {
                auto l = diffWaysToCompute(s.substr(0, i));
                auto r = diffWaysToCompute(s.substr(i + 1));
                for(int a : l) {
                    for(int b : r) {
                        if(c == '+')
                            tmp.push_back(a + b);
                        else if(c == '-')
                            tmp.push_back(a - b);
                        else if(c == '*')
                            tmp.push_back(a * b);
                    }
                }
            }
        }
        if(tmp.empty())
            tmp.push_back(stoi(s));
        return m[s] = tmp;
    }

private:
    unordered_map<string, vector<int>> m;
};
