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
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        f(root, 0, ans);
        return ans;
    }

private:
    void f(TreeNode *root, int tmp, int &ans) {
        if(!root)
            return;

        tmp <<= 1;
        tmp |= root->val;
        if(!root->left && !root->right) {
            ans += tmp;
            return;
        }
        f(root->left, tmp, ans);
        f(root->right, tmp, ans);
    }
};
