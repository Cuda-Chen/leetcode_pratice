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
    ListNode *head;

    Solution(ListNode* head) : head(head) {
        
    }
    
    int getRandom() {
        int ans = -1;
        int i = 1;
        for(auto cur = head; cur; cur = cur->next, i++) {
            if(rand() % i == 0)
                ans = cur->val;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
