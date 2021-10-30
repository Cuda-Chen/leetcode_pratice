// https://zxi.mytechroad.com/blog/data-structure/leetcode-225-implement-stack-using-queues/
// for every push, shift the queue (n – 1) times such that the last element becomes the first element in the queue.

class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i = 1; i < q.size(); i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
    
private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
