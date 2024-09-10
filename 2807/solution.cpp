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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *a = head, *b = head->next;
        while(a && b) {
            int e = std::gcd(a->val, b->val);
            ListNode *n = new ListNode(e);
            a->next = n;
            n->next = b;
            a = b;
            b = b->next;
        }
        return head;
    }
};
