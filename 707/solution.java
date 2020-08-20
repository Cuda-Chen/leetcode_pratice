class Node {
    public int val;
    public Node next;
    
    public Node(int value) {
        this.val = value;
        this.next = null;
    }
}

class MyLinkedList {
    Node head, tail;
    int size;
    
    /** Initialize your data structure here. */
    public MyLinkedList() {
        head = tail = null;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if(index >= size) {
            return -1;
        }
        
        Node iter = head;
        while(index > 0) {
            iter = iter.next;
            index--;
        }
        return iter.val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        Node temp = new Node(val);
        if(size == 0) {
            head = tail = temp;
        } else {
            temp.next = head;
            head = temp;
        }
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        Node temp = new Node(val);
        if(size == 0) {
            head = tail = temp;
        } else {
            tail.next = temp;
            tail = temp;
        }
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if(index > size) {
            return;
        } else if(index == 0) {
            addAtHead(val);
            return;
        } else if(index == size) {
            addAtTail(val);
            return;
        }
        
        Node iter = head;
        while(index > 1) {
            iter = iter.next;
            index--;
        }
        Node temp = iter.next;
        iter.next = new Node(val);
        iter.next.next = temp;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if(index < size) {
            Node iter = head;
            if(index == 0) {
                head = head.next;
            } else {
                while(index > 1) {
                    iter = iter.next;
                    index--;
                }
                Node temp = iter.next;
                iter.next = iter.next.next;
                if(iter.next == null) {
                    tail = iter;
                }
            }
            size--;
        }
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
