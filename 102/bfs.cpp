// BFS (O(n))

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) {
            return {};
        }
        
        vector<vector<int>> result;
        vector<TreeNode *> current, next;
        current.push_back(root);
        while(!current.empty()) {
            result.push_back({});
            for(TreeNode *node: current) {
                result.back().push_back(node->val);
                if(node->left) {
                    next.push_back(node->left);
                }
                if(node->right) {
                    next.push_back(node->right);
                }
            }
            current.swap(next);
            next.clear();
        }
        
        return result;
    }
};
