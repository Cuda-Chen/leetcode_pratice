// https://www.cnblogs.com/grandyang/p/7500082.html
// recursive (preorder traversal)

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode *> result;
        unordered_map<string, int> map;
        helper(root, map, result);
        return result;
    }
    
private:
    string helper(TreeNode *root, unordered_map<string, int> &map, vector<TreeNode *> &result) {
        if(!root) return "#";
        string str = to_string(root->val) + "," +
            helper(root->left, map, result) + "," +
            helper(root->right, map, result);
        if(map[str] == 1) result.push_back(root);
        map[str]++;
        return str;
    }
};
