// https://zxi.mytechroad.com/blog/tree/leetcode-230-kth-smallest-element-in-a-bst/
// inorder traversal (optimized)
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
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
    
private:
    int inorder(TreeNode *root, int &k) {
        if(!root) return -1;
        int temp = inorder(root->left, k);
        if(k == 0) return temp;
        if(--k == 0) return root->val;
        return inorder(root->right, k);
    }
};
