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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *cur = head;
        int cnt = 0;
        while(cur) {
            cnt++;
            cur = cur->next;
        }
        
        vector<ListNode *> ans(k);
        int a = cnt / k;
        cnt = cnt % k;
        cur = head;
        ListNode *prev = nullptr;

        if(a == 0) {
            int idx = 0;
            while(cnt--) {
                ans[idx] = cur;
                prev = cur;
                cur = cur->next;
                idx++;

                prev->next = nullptr;
            }

            return ans;
        }

        for(int i = 0; i < k; i++) {
            ans[i] = cur;
            for(int j = 0; j < a; j++) {
                prev = cur;
                cur = cur->next;
            }

            if(cnt) {
                prev = cur;
                cur = cur->next;
                cnt--;
            }

            prev->next = nullptr;
        }
        
        return ans;
    }
};
