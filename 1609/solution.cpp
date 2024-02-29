// LeetCode 1609. Even Odd Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode *> q{{root}};
        int idx = 0;
        while(!q.empty()) {
            int sz = q.size();
            int eo = idx % 2;
            int tmp = (!eo) ? INT_MIN : INT_MAX;
            while(sz--) {
                auto t = q.front();
                q.pop();
                if((!eo && (t->val % 2 != 1)) ||
                   (eo && (t->val % 2 != 0)))
                   return false;
                if((!eo && (tmp >= t->val)) || 
                   (eo && (tmp <= t->val)))
                    return false;
                tmp = t->val;
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            idx++;
        }
        return true;
    }
};
