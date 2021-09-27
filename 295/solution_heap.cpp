// https://zxi.mytechroad.com/blog/leetcode/leetcode-295-find-median-from-data-stream/
// min/max heap (priority_queue)

class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(l.empty() || num <= l.top())
            l.push(num);
        else
            r.push(num);
        
        if(l.size() < r.size()) {
            l.push(r.top());
            r.pop();
        } else if(l.size() - r.size() == 2) {
            r.push(l.top());
            l.pop();
        }
    }
    
    double findMedian() {
        return (l.size() > r.size())
            ? (static_cast<double>(l.top()))
            : (static_cast<double>(l.top() + r.top()) / 2);
    }
    
private:
    priority_queue<int, vector<int>, less<int>> l;
    priority_queue<int, vector<int>, greater<int>> r;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
