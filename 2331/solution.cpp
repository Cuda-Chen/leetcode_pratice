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
    bool evaluateTree(TreeNode* root) {
        return f(root) == 1;
    }

private:
    int f(TreeNode *root) {
        int val = root->val;
        if(val == 0 || val == 1)
            return val;

        int l = f(root->left);
        int r = f(root->right);
        int ret;
        if(val == 2)
            ret = l | r;
        else if(val == 3)
            ret = l & r;
        return ret;
    }
};
