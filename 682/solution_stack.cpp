// stack
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        
        for(auto op : ops) {
            if(op[0] == '+') {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.push(b);
                s.push(a + b);
            } else if(op[0] == 'D') {
                int a = s.top();
                s.push(a * 2);
            } else if(op[0] == 'C') {
                s.pop();
            } else {
                s.push(stoi(op));
            }
        }
        
        int ans = 0;
        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};
