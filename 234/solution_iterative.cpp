/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow, *fast;
        slow = fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast)
            slow = slow->next;
        
        slow = reverse(slow);
        while(slow && head) {
            if(slow->val != head->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
    
    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr;
        while(head) {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
