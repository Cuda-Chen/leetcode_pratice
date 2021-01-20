// stack

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n % 2 == 1) return false;
        stack<char> st;
        for(int i = 0; i < n; i++) {
            if(s[i] == '{' || s[i] == '[' || s[i] == '(')
                st.push(s[i]);
            
            if(s[i] == '}' || s[i] == ']' || s[i] == ')') {
                if(st.empty()) return false;
                char temp = st.top(); st.pop();
                if(s[i] == '}' && temp == '{') continue;
                else if(s[i] == ']' && temp == '[') continue;
                else if(s[i] == ')' && temp == '(') continue;
                else return false;
            }
        }
        return st.empty() ? true : false;
    }
};
