// https://zxi.mytechroad.com/blog/leetcode/leetcode-295-find-median-from-data-stream/
// balanced binary search tree (multset)

class MedianFinder {
public:
    MedianFinder() : l(m.end()), r(m.end()) {
        
    }
    
    void addNum(int num) {
        if(m.empty()) {
            l = r = m.insert(num);
            return;
        }
        
        m.insert(num);
        size_t n = m.size();
        
        if(n & 1) {
            if(num >= *r)
                l = r;
            else
                l = --r;
        } else {
            if(num >= *r)
                ++r;
            else
                --l;
        }
    }
    
    double findMedian() {
        return static_cast<double>(*l + *r) / 2;
    }
    
private:
    multiset<int> m;
    multiset<int>::const_iterator l, r;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
