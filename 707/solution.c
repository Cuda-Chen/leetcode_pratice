
typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node* NodeCreate(int value) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->val = value;
    temp->next = NULL;
    return temp;
}

typedef struct {
    Node *head;
    Node *tail;
    int size;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *temp = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    temp->head = temp->tail = NULL;
    temp->size = 0;
    return temp;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index >= obj->size) {
        return -1;
    }
    
    Node *iter = obj->head;
    while(index > 0) {
        iter = iter->next;
        index--;
    }
    return iter->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node *temp = NodeCreate(val);
    if(obj->size == 0) {
        obj->head = obj->tail = temp;
    } else {
        temp->next = obj->head;
        obj->head = temp;
    }
    obj->size++;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node *temp = NodeCreate(val);
    if(obj->size == 0) {
        obj->head = obj->tail = temp;
    } else {
        obj->tail->next = temp;
        obj->tail = temp;
    }
    obj->size++;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index > obj->size) {
        return;
    } else if(index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    } else if(index == obj->size) {
        myLinkedListAddAtTail(obj, val);
        return;
    }
    
    Node *iter = obj->head;
    while(index > 1) {
        iter = iter->next;
        index--;
    }
    Node *temp = iter->next;
    iter->next = NodeCreate(val);
    iter->next->next = temp;
    obj->size++;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index < obj->size) {
        Node *iter = obj->head;
        if(index == 0) {
            obj->head = iter->next;
            free(iter);
        } else {
            while(index > 1) {
                iter = iter->next;
                index--;
            }
            Node *temp = iter->next;
            iter->next = iter->next->next;
            free(temp);
            if(iter->next == NULL) {
                obj->tail = iter;
            }
        }
        obj->size--;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    Node *iter = obj->head;
    while(obj->head != NULL) {
        iter = obj->head;
        obj->head = iter->next;
        free(iter);
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
