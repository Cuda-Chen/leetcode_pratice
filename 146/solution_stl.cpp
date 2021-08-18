// https://zxi.mytechroad.com/blog/hashtable/leetcode-146-lru-cache/
// O(1) operation
// hash table + doubly linked list

class LRUCache {
public:
    LRUCache(int capacity) {
        size = capacity;        
    }
    
    int get(int key) {
        auto it = map.find(key);
        if(it != map.cend()) {
            cache.splice(cache.begin(), cache, it->second);
            return it->second->second;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        if(it != map.cend()) {
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
        } else {
            if(map.size() == size) {
                auto &node = cache.back();
                map.erase(node.first);
                cache.pop_back();
            }
            cache.emplace_front(key, value);
            map[key] = cache.begin();
        }
    }
    
private:
    int size;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
