// https://zxi.mytechroad.com/blog/tree/leetcode-1373-maximum-sum-bst-in-binary-tree/
// post-order traversal

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
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    
private:
    // lo, hi, sum, valid
    tuple<int, int, int, bool> dfs(TreeNode *root, int &ans) {
        if(!root) return {INT_MAX, INT_MIN, 0, true};
        auto [ll, lh, ls, lv] = dfs(root->left, ans);
        auto [rl, rh, rs, rv] = dfs(root->right, ans);
        bool valid = lv && rv && root->val > lh && root->val < rl;
        int sum = valid ? ls + rs + root->val : -1;
        ans = max(ans, sum);
        return {min(ll, root->val), max(rh, root->val), sum, valid};
    }
};
