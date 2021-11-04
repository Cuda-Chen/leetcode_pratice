// DFS
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
    int sumOfLeftLeaves(TreeNode* root) {
        ans = 0;
        helper(root, false);
        return ans;
    }
    
private:
    int ans;
    
    void helper(TreeNode *root, bool flag) {
        if(!root->left && !root->right) {
            if(flag)
                ans += root->val;
            return;
        }
        
        if(root->left) {
            flag = true;
            helper(root->left, flag);
        }
        if(root->right) {
            flag = false;
            helper(root->right, flag);
        }
    }
};
