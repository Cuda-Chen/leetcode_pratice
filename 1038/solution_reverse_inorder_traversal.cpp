// https://zxi.mytechroad.com/blog/tree/leetcode-538-convert-bst-to-greater-tree/
// reverse inorder traversal
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
    TreeNode* bstToGst(TreeNode* root) {
        rinorder(root);
        return root;
    }
    
private:
    int sum = 0;
    void rinorder(TreeNode *root) {
        if(!root) return;
        rinorder(root->right);
        root->val = (sum += root->val);
        rinorder(root->left);
    }
};
