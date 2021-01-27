// https://zxi.mytechroad.com/blog/uncategorized/leetcode-95-unique-binary-search-trees-ii/
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
        if(!n) return { nullptr };
        const auto &ans = generateTrees(1, n);
        return ans;
    }
    
    vector<TreeNode *> generateTrees(int l, int r) {
        if(l > r) return { nullptr };
        vector<TreeNode *> ans;
        for(int i = l; i <= r; i++) {
            for(TreeNode *left : generateTrees(l, i - 1)) {
                for(TreeNode *right : generateTrees(i + 1, r)) {
                    ans.push_back(new TreeNode(i));
                    ans.back()->left = left;
                    ans.back()->right = right;
                }
            }
        }
        return ans;
    }
};
