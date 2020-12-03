// in-order traversal
// out-of-place

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
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> temp = inorder(root);
        
        TreeNode *head = new TreeNode(temp[0]);
        TreeNode *dummy = head;
        for(int i = 1; i < temp.size(); i++) {
            dummy->right = new TreeNode(temp[i]);
            dummy = dummy->right;
        }
        
        return head;
    }
private:
    // https://shubo.io/iterative-binary-tree-traversal/
    vector<int> inorder(TreeNode *root) {
        vector<int> result;
        if(!root) return result;
        
        stack<TreeNode *> s;
        TreeNode *current = root;
        while(current || !s.empty()) {
            if(current) {
                s.push(current);
                current = current->left;
            } else {
                TreeNode *node = s.top(); s.pop();
                result.push_back(node->val);
                current = node->right;
            }
        }
        
        return result;
    }
};
