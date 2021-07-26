// https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-1/wan-quan-er-cha-shu-jie-dian-shu
// O(lgN * lgN)
// Use the property of full binary tree
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
    int countNodes(TreeNode* root) {
        TreeNode *l = root, *r = root;
        
        int hl = 0, hr = 0;
        while(l) {
            l = l->left;
            hl++;
        }
        while(r) {
            r = r->right;
            hr++;
        }
        
        if(hl == hr)
            return static_cast<int>(pow(2, hl) - 1);
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
