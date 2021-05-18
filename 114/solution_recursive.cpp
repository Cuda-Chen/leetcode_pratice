// https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-1/er-cha-shu-xi-lie-1#san-suan-fa-shi-jian
// recursive
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
    void flatten(TreeNode* root) {
        if(!root) return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        
        root->left = nullptr;
        root->right = l;
        
        TreeNode *temp = root;
        while(temp->right) temp = temp->right;
        temp->right = r;
    }
};
