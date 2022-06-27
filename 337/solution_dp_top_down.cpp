// DP (top-down)

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
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        if(m.count(root))
            return m[root];
        int ll = root->left ? rob(root->left->left) : 0,
            lr = root->left ? rob(root->left->right) : 0,
            rl = root->right ? rob(root->right->left) : 0,
            rr = root->right ? rob(root->right->right) : 0;
        return m[root] = max(root->val + ll + lr + rl + rr,
                             rob(root->left) + rob(root->right));
    }
    
private:
    unordered_map<TreeNode *, int> m;
};
