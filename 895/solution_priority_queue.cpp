// https://zxi.mytechroad.com/blog/desgin/leetcode-895-maximum-frequency-stack/
// priority queue

class FreqStack {
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        int key = ((++f[val]) << 16 | (++seq));
        q.emplace(key, val);
    }
    
    int pop() {
        int x = q.top().second;
        q.pop();
        if((--f[x]) == 0)
            f.erase(x);
        return x;
    }
    
private:
    int seq = 0;
    unordered_map<int, int> f;
    priority_queue<pair<int, int>> q;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
