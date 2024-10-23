/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        vector<int> tmp;
        queue<TreeNode *> q{{root}};
        while (!q.empty()) {
            int sum = 0;
            int sz = q.size();
            while (sz--) {
                auto t = q.front();
                q.pop();
                sum += t->val;
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            tmp.push_back(sum);
        }

        f(root, -1, -1, tmp, 0);
        return root;
    }

private:
    void f(TreeNode *root, int l, int r, vector<int> &v, int depth)
    {
        if (!root)
            return;

        int tmp = v[depth];
        if (l != -1)
            tmp -= l;
        if (r != -1)
            tmp -= r;
        if (l == -1 && r == -1)  // root node
            tmp -= root->val;
        root->val = tmp;

        l = root->left ? root->left->val : -1;
        r = root->right ? root->right->val : -1;

        f(root->left, l, r, v, depth + 1);
        f(root->right, l, r, v, depth + 1);
    }
};
