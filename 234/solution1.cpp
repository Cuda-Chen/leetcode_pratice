// naive
// Get the array, then compare the reverse of array is equal or not.
// O(n) space

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
        vector<int> arr;
        ListNode *node = head;
        while(node) {
            arr.emplace_back(node->val);
            node = node->next;
        }
        vector<int> reverseArr = arr;
        std::reverse(arr.begin(), arr.end());
        return arr == reverseArr;
    }
};
