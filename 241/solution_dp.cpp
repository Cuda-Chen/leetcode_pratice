// https://zxi.mytechroad.com/blog/leetcode/leetcode-241-different-ways-to-add-parentheses/
// DP (top-down)

namespace myfunc {
    inline int add(int a, int b) { return a + b; }
    inline int minus(int a, int b) { return a - b; }
    inline int mul(int a, int b) { return a * b; }
}

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return ways(expression);
    }
    
private:
    unordered_map<string, vector<int>> m;
    
    const vector<int> ways(const string &input) {
        if(m.count(input)) return m[input];
        
        vector<int> ans;
        
        for(int i = 0; i < input.size(); i++) {
            char op = input[i];
            
            if(op == '+' || op == '-' || op == '*') {
                const string left = input.substr(0, i);
                const string right = input.substr(i + 1);
                const vector<int> l = ways(left);
                const vector<int> r = ways(right);
                std::function<int(int, int)> f;
                
                switch(op) {
                    case '+':
                        f = myfunc::add;
                        break;
                    case '-':
                        f = myfunc::minus;
                        break;
                    case '*':
                        f = myfunc::mul;
                        break;
                }
                
                for(int a : l) {
                    for(int b : r)
                        ans.push_back(f(a, b));
                }
            }
        }
        
        if(ans.empty())
            ans.push_back(stoi(input));
        
        m[input].swap(ans);
        
        return m[input];
    }
};
