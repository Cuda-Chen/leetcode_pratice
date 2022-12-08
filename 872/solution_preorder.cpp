// preorder traversal

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        traverse(root1, arr1);
        traverse(root2, arr2);
        if(arr1.size() != arr2.size())
            return false;
        for(int i = 0; i < arr1.size(); i++) {
            if(arr1[i] != arr2[i])
                return false;
        }
        return true;
    }

private:
    void traverse(TreeNode *a, vector<int> &arr) {
        if(!a)
            return;
        if(!a->left && !a->right) {
            arr.push_back(a->val);
            return;
        }
        if(a->left)
            traverse(a->left, arr);
        if(a->right)
            traverse(a->right, arr);
    }
};
