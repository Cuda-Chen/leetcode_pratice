// recursive
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
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        preorder = pre;
        inorder = in;
        
        for(int i = 0; i < inorder.size(); i++)
            pos[inorder[i]] = i;
        
        return build(0, inorder.size() - 1, 0, preorder.size() - 1);
    }
    
private:
    unordered_map<int, int> pos;
    vector<int> preorder, inorder;
    
    TreeNode *build(int is, int ie, int ps, int pe) {
        if(ps > pe) return nullptr;
        
        int im = pos[preorder[ps]];
        int pm = ps + (im - is);
        
        TreeNode *root = new TreeNode(preorder[ps]);
        root->left = build(is, im - 1, ps + 1, pm);
        root->right = build(im + 1, ie, pm + 1, pe);
        
        return root;
    }
};
