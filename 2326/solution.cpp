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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));

        int y = 0, x = 0;
        int d = 0;
        int l = 0, t = 0, r = n - 1, b = m - 1;
        ListNode *cur = head;
        int cnt = 0;
        while(cur && cnt < (n * m - 1)) {
            switch(d) {
                case 0:
                    while(x < r && cur) {
                        ans[y][x++] = cur->val;
                        cur = cur->next;
                        cnt++;
                    }
                    t++;
                    break;
                case 1:
                    while(y < b && cur) {
                        ans[y++][x] = cur->val;
                        cur = cur->next;
                        cnt++;
                    }
                    r--;
                    break;
                case 2:
                    while(x > l && cur) {
                        ans[y][x--] = cur->val;
                        cur = cur->next;
                        cnt++;
                    }
                    b--;
                    break;
                case 3:
                    while(y > t && cur) {
                        ans[y--][x] = cur->val;
                        cur = cur->next;
                        cnt++;
                    }
                    l++;
                    break;
            }
            d = (d + 1) % 4;
        }

        if(cur)
            ans[y][x] = cur->val;
        return ans;
    }
};
