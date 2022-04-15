// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/discuss/1679907/Extremely-concise-C%2B%2B-indirect-pointer-solution
// indirect pointer

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode **slow, **fast;
        slow = fast = &head;
        while(*fast) {
            fast = &(*fast)->next;
            while(*fast && (*fast)->val == (*slow)->val)
                fast = &(*fast)->next;
            if(*slow && (*slow)->next == *fast)
                slow = &(*slow)->next;
            else
                *slow = *fast;
        }
        return head;
    }
};
