/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *result = NULL;
    struct ListNode *l1Ptr, *l2Ptr, *current;
    l1Ptr = l1;
    l2Ptr = l2;
    int carry = 0;
    int sum = 0;
    int remain = 0;
    
    if(l1 == NULL || l2 == NULL) {
        return (l1 == NULL) ? l2 : l1;
    }
    
    while(l1Ptr != NULL && l2Ptr != NULL) {
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        sum = l1Ptr->val + l2Ptr->val + carry;
        carry = sum / 10;
        remain = sum % 10;
        temp->val = remain;
        
        // if processing the first node
        if(result == NULL) {
            result = current = temp;
        } else {
            current->next = temp;
            current = current->next;
        }
        
        l1Ptr = l1Ptr->next;
        l2Ptr = l2Ptr->next;
    }
    
    // if l1 remains unprocessed data
    while(l1Ptr != NULL) {
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        sum = l1Ptr->val + carry;
        carry = sum / 10;
        remain = sum % 10;
        temp->val = remain;
        
        current->next = temp;
        current = current->next;
        l1Ptr = l1Ptr->next;
    }
    
    while(l2Ptr != NULL) {
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        sum = l2Ptr->val + carry;
        carry = sum / 10;
        remain = sum % 10;
        temp->val = remain;
        
        current->next = temp;
        current = current->next;
        l2Ptr = l2Ptr->next;
    }
    
    // solve overflow
    if(carry > 0) {
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val = carry;
        
        current->next = temp;
        current = current->next;
    }
    
    current->next = NULL;
    
    return result;
}


