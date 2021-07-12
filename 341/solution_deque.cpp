// https://www.cnblogs.com/grandyang/p/5358793.html
// deque
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = 0; i < nestedList.size(); i++)
            d.push_back(nestedList[i]);
    }
    
    int next() {
        NestedInteger t = d.front();
        d.pop_front();
        return t.getInteger();
    }
    
    bool hasNext() {
        while(!d.empty()) {
            NestedInteger t = d.front();
            if(t.isInteger()) return true;
            d.pop_front();
            for(int i = 0; i < t.getList().size(); i++)
                d.insert(d.begin() + i, t.getList()[i]);
        }
        return false;
    }
    
private:
    deque<NestedInteger> d;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
