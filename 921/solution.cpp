class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(char c : s) {
            if(st.empty() || c == '(')
                st.push(c);
            else if(st.top() == '(')
                st.pop();
            else
                st.push(c);
        }

        return st.size();
    }
};
