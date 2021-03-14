// naive
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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> arr;
        ListNode *node = head;
        while(node) {
            arr.push_back(node->val);
            node = node->next;
        }
        int n = arr.size();
        
        
        int temp = arr[k - 1]; // front
        arr[k - 1] = arr[n - k]; // back
        arr[n - k] = temp;
        
        ListNode *ans = new ListNode();
        ListNode *dummy = ans;
        for(int elem : arr) {
            ans->next = new ListNode(elem);
            ans = ans->next;
        }
        
        return dummy->next;
    }
};
