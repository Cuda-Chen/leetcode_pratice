// pre-order traversal

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
    bool twoSumBSTs(TreeNode* p, TreeNode* q, int target) {
        if(!p || !q)
            return false;
        unordered_set<int> m;
        preorder(p, m);
        return preorder_get_ans(q, m, target);
    }

private:
    void preorder(TreeNode *p, unordered_set<int> &m) {
        if(!p)
            return;
        m.insert(p->val);
        preorder(p->left, m);
        preorder(p->right, m);
    }

    bool preorder_get_ans(TreeNode *p, unordered_set<int> &m, int target) {
        if(!p)
            return false;
        int comp = target - p->val;
        if(m.count(comp))
            return true;
        return preorder_get_ans(p->left, m, target)
            || preorder_get_ans(p->right, m, target);
    }
};
