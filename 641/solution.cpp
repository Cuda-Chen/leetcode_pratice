class MyCircularDeque {
public:
    MyCircularDeque(int k) : sz(0), capacity(k) {
        dummy = new Node();
        dummy->v = 0;
        dummy->prev = dummy;
        dummy->next = dummy;
    }
    
    bool insertFront(int value) {
        if(this->isFull())
            return false;

        Node *n = new Node();
        Node *t = dummy->next;
        n->v = value;

        dummy->next = n;
        n->next = t;
        n->prev = dummy;
        t->prev = n;
        sz++;
        return true;
    }
    
    bool insertLast(int value) {
        if(this->isFull())
            return false;

        Node *n = new Node();
        Node *t = dummy->prev;
        n->v = value;

        dummy->prev = n;
        n->prev = t;
        n->next = dummy;
        t->next = n;
        sz++;
        return true;
    }
    
    bool deleteFront() {
        if(this->isEmpty())
            return false;

        Node *d = dummy->next;
        Node *n = dummy->next->next;
        dummy->next = n;
        n->prev = dummy;
        delete(d);
        sz--;
        return true;
    }
    
    bool deleteLast() {
        if(this->isEmpty())
            return false;

        Node *d = dummy->prev;
        Node *n = dummy->prev->prev;
        dummy->prev = n;
        n->next = dummy;
        delete(d);
        sz--;
        return true;
    }
    
    int getFront() {
        return this->isEmpty() ? -1 : dummy->next->v;
    }
    
    int getRear() {
        return this->isEmpty() ? -1 : dummy->prev->v;
    }
    
    bool isEmpty() {
        return sz == 0;
    }
    
    bool isFull() {
        return sz >= capacity;
    }

private:
    struct Node {
        int v;
        Node *prev;
        Node *next;
    };

    Node *dummy;
    int sz;
    int capacity;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
