// https://zxi.mytechroad.com/blog/hashtable/leetcode-460-lfu-cache/
// C++ STL
// Using this not only clumsy but also slower

class LFUCache {
public:
    LFUCache(int capacity) {
        size = capacity;
        min_freq = 0;
    }
    
    int get(int key) {
        auto it = n.find(key);
        if(it == n.cend()) return -1;
        touch(it->second);
        return it->second.value;
    }
    
    void put(int key, int value) {
        if(size == 0) return;
        
        auto it = n.find(key);
        if(it != n.cend()) {
            it->second.value = value;
            touch(it->second);
            return;
        }
        
        if(n.size() == size) {
            int key_to_evict = l[min_freq].back();
            l[min_freq].pop_back();
            n.erase(key_to_evict);
        }
        int cur_freq = 1;
        min_freq = cur_freq;
        l[cur_freq].push_front(key);
        n[key] = {key, value, cur_freq, l[cur_freq].cbegin()};
    }
    
private:
    struct Node {
        int key, value;
        int freq;
        list<int>::const_iterator it;
    };
    int size;
    int min_freq;
    unordered_map<int, Node> n;
    unordered_map<int, list<int>> l;
    
    void touch(Node &node) {
        int prev_freq = node.freq;
        int cur_freq = ++node.freq;
        
        l[prev_freq].erase(node.it);
        if(l[prev_freq].empty() && min_freq == prev_freq) {
            l.erase(prev_freq);
            ++min_freq;
        }
        
        l[cur_freq].push_front(node.key);
        node.it = l[cur_freq].cbegin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
