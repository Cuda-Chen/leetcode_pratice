// https://labuladong.gitbook.io/algo/di-yi-zhang-shou-ba-shou-shua-shu-ju-jie-gou/shou-ba-shou-shua-lian-biao-ti-mu/di-gui-fan-zhuan-lian-biao-de-yi-bu-fen#san-fan-zhuan-lian-biao-de-yi-bu-fen
// https://labuladong.gitbook.io/algo/di-yi-zhang-shou-ba-shou-shua-shu-ju-jie-gou/shou-ba-shou-shua-lian-biao-ti-mu/di-gui-fan-zhuan-lian-biao-de-yi-bu-fen#er-fan-zhuan-lian-biao-qian-n-ge-jie-dian
// recursive
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == 1) {
            head = reverseN(head, right);
            return head;
        }
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
    
    ListNode *reverseN(ListNode *head, int n) {
        if(n == 1) {
            successor = head->next;
            return head;
        }
        
        ListNode *last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        
        return last;
    }
    
private:
    ListNode *successor;
};
