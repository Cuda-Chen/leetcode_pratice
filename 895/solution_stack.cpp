// https://zxi.mytechroad.com/blog/desgin/leetcode-895-maximum-frequency-stack/
// stack

class FreqStack {
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        auto it = f.find(val);
        if(it == f.end())
            it = f.emplace(val, 0).first;
        int freq = ++it->second;
        if(stacks.size() < freq)
            stacks.push_back({});
        stacks[freq - 1].push(val);
    }
    
    int pop() {
        int x = stacks.back().top();
        stacks.back().pop();
        if(stacks.back().empty())
            stacks.pop_back();
        auto it = f.find(x);
        if((--it->second) == 0)
            f.erase(it);
        return x;
    }
    
private:
    unordered_map<int, int> f;
    vector<stack<int>> stacks;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
