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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *a = reverse(l1), *b = reverse(l2);
        
        int carry = 0;
        //ListNode *ans = new ListNode(0), **ptr = &ans;
        ListNode dummy(0), *ans = &dummy;
        while(a && b) {
            int sum = a->val + b->val + carry;
            carry = sum / 10;
            sum %= 10;
            ans->next = new ListNode(sum);
            a = a->next;
            b = b->next;
            ans = ans->next;
        }
        while(a) {
            int sum = a->val + carry;
            carry = sum / 10;
            sum %= 10;
            ans->next = new ListNode(sum);
            a = a->next;
            ans = ans->next;
        }
        while(b) {
            int sum = b->val + carry;
            carry = sum / 10;
            sum %= 10;
            ans->next = new ListNode(sum);
            b = b->next;
            ans = ans->next;
        }
        while(carry) {
            ans->next = new ListNode(carry % 10);
            carry /= 10;
        }
        
        ans = reverse(dummy.next);
        /*for(ListNode *ptr = dummy.next; ptr; ptr = ptr->next) {
            printf("%d ", ptr->val);
        }*/
        return ans;
    }

private:
    ListNode *reverse(ListNode *head) {
        ListNode *cur = head, *prev = nullptr;
        while(cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
