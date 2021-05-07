// https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye/k-ge-yi-zu-fan-zhuan-lian-biao
// recursive + iterative

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;
        
        ListNode *a, *b;
        a = b = head;
        for(int i = 0; i < k; i++) {
            if(!b) return head;
            b = b->next;
        }
        ListNode *newHead = reverseList(a, b);
        a->next = reverseKGroup(b, k);
        return newHead;
    }
    
    ListNode *reverseList(ListNode *a, ListNode *b) {
        ListNode *prev = nullptr;
        ListNode *cur = a;
        while(cur != b) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
