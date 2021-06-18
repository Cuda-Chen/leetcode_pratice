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
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
    
private:
    vector<TreeNode*> build(int lo, int hi) {
        vector<TreeNode*> ans;
        if(lo > hi) {
            ans.push_back(nullptr);
            return ans;
        }
        
        for(int i = lo; i <= hi; i++) {
            vector<TreeNode*> leftTree = build(lo, i - 1);
            vector<TreeNode*> rightTree = build(i + 1, hi);
            
            for(auto left : leftTree) {
                for(auto right : rightTree) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
    }
};
