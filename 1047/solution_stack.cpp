// stack
class Solution {
public:
    string removeDuplicates(string str) {
        stack<char> s;
        
        for(char c : str) {
            if(!s.empty() && s.top() == c) // using !s.empty() to prevent invalid access
                s.pop();
            else
                s.push(c);
        }
        
        string ans;
        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }
        std::reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
