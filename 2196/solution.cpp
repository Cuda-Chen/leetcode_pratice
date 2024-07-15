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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int r = -1;
        unordered_map<int, unordered_map<int, int>> m; // {parent, {child, left|right}}
        unordered_set<int> children;
        for(auto &d : descriptions) {
            int p = d[0];
            int c = d[1];
            int lr = d[2];
            if(!m.count(p))
                m[p] = {};
            children.insert(c);
            m[p][c] = lr;
        }

        // find root node
        for(auto &[k, _] : m) {
            if(!children.count(k)) {
                r = k;
                break;
            }
        }

        TreeNode *ans = f(r, m);
        return ans;
    }

private:
    TreeNode *f(
        int root,
        unordered_map<int, unordered_map<int, int>> &m
    ) {
        TreeNode *ret = new TreeNode(root);
        for(auto kv : m[root]) {
            int c = kv.first;
            int lr = kv.second;
            if(lr & 1)
                ret->left = f(c, m);
            else
                ret->right = f(c, m);
        }
        return ret;
    }
};
