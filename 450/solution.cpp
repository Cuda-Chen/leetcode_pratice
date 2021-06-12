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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        
        if(root->val == key) {
            // case 1 and 2
            if(!root->left) return root->right;
            if(!root->right) return root->left;
            
            // case 3
            TreeNode *min = getMinNode(root->right);
            root->val = min->val;
            root->right = deleteNode(root->right, min->val);
        } else if(root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        
        return root;
    }
    
private:
    TreeNode *getMinNode(TreeNode *node) {
        while(node->left) node = node->left;
        return node;
    }
};
