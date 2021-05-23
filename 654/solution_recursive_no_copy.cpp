// recursive (no copy)
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }
    
private:
    TreeNode *build(vector<int> &nums, int l, int r) {
        if(l >= r) return nullptr;
        
        auto it = max_element(nums.begin() + l, nums.begin() + r);
        TreeNode *root = new TreeNode(*it);
        root->left = build(nums, l, it - nums.begin());
        root->right = build(nums, it - nums.begin() + 1, r);
        
        return root;
    }
};
