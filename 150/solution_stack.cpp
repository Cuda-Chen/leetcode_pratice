// stack (post-order traversal)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int a, b;
        
        for(string token : tokens) {
            if(token == "+") {
                b = s.top(); s.pop();
                a = s.top(); s.pop();
                s.push(a + b);
            } else if(token == "-") {
                b = s.top(); s.pop();
                a = s.top(); s.pop();
                s.push(a - b);
            } else if(token == "*") {
                b = s.top(); s.pop();
                a = s.top(); s.pop();
                s.push(a * b);
            } else if(token == "/") {
                b = s.top(); s.pop();
                a = s.top(); s.pop();
                s.push(a / b);
            } else {
                s.push(stoi(token));
            }
        }
        
        return s.top();
    }
};
