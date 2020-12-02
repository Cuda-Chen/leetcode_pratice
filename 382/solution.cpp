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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->node = head;
        while(head) {
            head = head->next;
            this->size++;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        if(size == 0) return 0;
        int v = rand() % size;
        cout << v << endl;
        ListNode *temp = this->node;
        while(v > 0) {
            temp = temp->next;
            v--;
        }
        
        return temp->val;
    }
    
private:
    int size = 0;
    ListNode *node = nullptr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
