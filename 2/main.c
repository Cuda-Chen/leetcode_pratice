/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    struct ListNode *result = dummy;
    int sum = 0;
    
    while(l1 || l2 || sum) {
        if(l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        result->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        result->next->val = sum % 10;
        result = result->next;
        sum /= 10;
    }
    
    result->next = NULL;
    
    return dummy->next;
}


