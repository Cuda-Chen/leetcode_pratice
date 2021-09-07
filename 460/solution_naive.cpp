// https://zxi.mytechroad.com/blog/hashtable/leetcode-460-lfu-cache/
// naive

class LFUCache {
public:
    LFUCache(int capacity) {
        size = capacity;
        tick = 0;
    }
    
    int get(int key) {
        auto it = map.find(key);
        if(it == map.cend()) return -1;
        touch(it->second);
        return it->second.value;
    }
    
    void put(int key, int value) {
        if(size == 0) return;
        
        auto it = map.find(key);
        if(it != map.cend()) {
            it->second.value = value;
            touch(it->second);
            return;
        }
        
        if(map.size() == size) {
            const Node &node = *cache.begin();
            map.erase(node.key);
            cache.erase(node);
        }
        Node node{key, value, 1, ++tick};
        map[key] = node;
        cache.insert(node);
    }
    
private:
    struct Node {
        int key, value;
        int freq;
        long tick;
        
        bool operator<(const Node &node) const {
            if(freq == node.freq)
                return tick < node.tick;
            return freq < node.freq;
        }
    };
    int size;
    long tick;
    unordered_map<int, Node> map;
    set<Node> cache;
    
    void touch(Node &node) {
        cache.erase(node);
        node.freq++;
        node.tick = ++tick;
        cache.insert(node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
