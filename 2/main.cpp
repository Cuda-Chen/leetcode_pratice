/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *result = dummy;
        int sum = 0;
        
        while(l1 || l2) {
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            result->next = new ListNode(sum % 10);
            result = result->next;
            sum /= 10;
        }
        
        if(sum > 0) {
            result->next = new ListNode(sum);
        }
        
        return dummy->next;
    }
};
