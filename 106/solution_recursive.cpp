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
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        inorder = in;
        postorder = post;
        
        for(int i = 0; i < inorder.size(); i++)
            pos[inorder[i]] = i;
        
        return build(0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    
private:
    unordered_map<int, int> pos;
    vector<int> inorder, postorder;
    
    TreeNode *build(int is, int ie, int ps, int pe) {
        if(ps > pe) return nullptr;
        
        int im = pos[postorder[pe]];
        int pm = ps + (im - is);
        
        TreeNode *root = new TreeNode(postorder[pe]);
        root->left = build(is, im - 1, ps, pm - 1);
        root->right = build(im + 1, ie, pm, pe - 1);
        
        return root;
    }
};
