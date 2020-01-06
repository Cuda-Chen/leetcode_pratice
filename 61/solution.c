/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if(!head) {
        return NULL;
    }
    int n = 0;
    struct ListNode *counterPtr = head;
    while(counterPtr) {
        n++;
        counterPtr = counterPtr->next;
    }
    
    k %= n;
    struct ListNode *fast = head, *slow = head;
    for(int i = 0; i < k; i++) {
        if(fast) {
            fast = fast->next;
        }
    }
    if(!fast) {
        return head;
    }
    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    
    fast->next = head;
    fast = slow->next;
    slow->next = NULL;
    
    return fast;
}


