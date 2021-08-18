// https://github.com/labuladong/fucking-algorithm/blob/master/%E9%AB%98%E9%A2%91%E9%9D%A2%E8%AF%95%E7%B3%BB%E5%88%97/LRU%E7%AE%97%E6%B3%95.md#c
// hash table + double linked list (from scratch)

// https://github.com/labuladong/fucking-algorithm/blob/master/%E9%AB%98%E9%A2%91%E9%9D%A2%E8%AF%95%E7%B3%BB%E5%88%97/LRU%E7%AE%97%E6%B3%95.md#c
// hash table + double linked list (from scratch)

struct node {
        int key, val;
        node *prev, *next;
        
        node() {}
        node(int key, int value) : key(key), val(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->size = capacity;
        head = new node();
        tail = new node();
        head->next = tail;
        tail->prev = head;  
    }
    
    int get(int key) {
        int ret = -1;
        if(map.count(key)) {
            node *temp = map[key];
            makeRecently(temp);
            ret = temp->val;
        }
        return ret;
    }
    
    void put(int key, int value) {
        if(map.count(key)) {
            node *temp = map[key];
            temp->val = value;
            makeRecently(temp);
        } else {
            node *cur = new node(key, value);
            if(map.size() == size) {
                node *temp = deleteCurrentNode(tail->prev);
                map.erase(temp->key);
            }
            moveToHead(cur);
            map[key] = cur;
        }
    }
    
private:
    unordered_map<int, node *> map;
    int size;
    node *head, *tail;
    
    void makeRecently(node *cur) {
        node *temp = deleteCurrentNode(cur);
        moveToHead(temp);
    }
    
    node *deleteCurrentNode(node *cur) {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        return cur;
    }
    
    void moveToHead(node *cur) {
        node *next = head->next;
        head->next = cur;
        cur->prev = head;
        next->prev = cur;
        cur->next = next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
