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
    int sumNumbers(TreeNode* root) {
        ans = 0;
        helper(root, to_string(root->val));
        return ans;
    }
    
private:
    int ans;
    
    void helper(TreeNode *root, string str) {
        if(!root->left && !root->right) {
            ans += stoi(str);
            return;
        }
        
        if(root->left) {
            string lstr = str + to_string(root->left->val);
            helper(root->left, lstr);
        }
        if(root->right) {
            string rstr = str + to_string(root->right->val);
            helper(root->right, rstr);
        }
    }
};
