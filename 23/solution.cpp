// divide and conquer

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() <= 0) return nullptr;
        return helper(lists, 0, lists.size() - 1);
    }
    
    ListNode *helper(vector<ListNode*>& lists, int l, int r) {
        if(l == r) {
            return lists[l];
        } else {
            int mid = l + (r - l) / 2;
            ListNode *l1 = helper(lists, l, mid);
            ListNode *l2 = helper(lists, mid + 1, r);
            return mergeTwoLists(l1, l2);
        }
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode();
        ListNode *head = dummy;
        
        while(l1 && l2) {
            if(l1->val < l2->val) {
                head->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                head->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            head = head->next;
        }
        
        while(l1) {
            head->next = new ListNode(l1->val);
            l1 = l1->next;
            head = head->next;
        }
        while(l2) {
            head->next = new ListNode(l2->val);
            l2 = l2->next;
            head = head->next;
        }
        
        return dummy->next;
    }
};
