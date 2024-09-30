class CustomStack {
public:
    CustomStack(int maxSize) : sz(maxSize) {
        
    }
    
    void push(int x) {
        if(s.size() >= sz)
            return;

        s.push(x);
    }
    
    int pop() {
        if(s.empty())
            return -1;

        int tmp = s.top();
        s.pop();
        return tmp;
    }
    
    void increment(int k, int val) {
        stack<int> tmp;
        while(!s.empty()) {
            tmp.push(s.top());
            s.pop();
        }

        while(!tmp.empty()) {
            int v = tmp.top();
            tmp.pop();
            if(k > 0)
                v += val;
            k--;
            s.push(v);
        }
    }

private:
    stack<int> s;
    int sz;
    int capacity;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
