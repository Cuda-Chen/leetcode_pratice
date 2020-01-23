// DFS (O(n))

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
        vector<vector<int>> result;
        DFS(root, 0 /* depth */, result);
        return result;
    }
    
private:
    void DFS(TreeNode *root, int depth, vector<vector<int>> &result) {
        if(!root) {
            return;
        }
        
        // works with pre/in/post-order
        while(result.size() <= depth) {
            result.push_back({});
        }
        // pre-order
        result[depth].push_back(root->val);
        DFS(root->left, depth + 1, result);
        DFS(root->right, depth + 1, result);
    }
};
