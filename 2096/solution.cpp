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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        /* Get the LCA */
        TreeNode *n = lca(root, startValue, destValue);

        string path = "";
        string s;
        f(n, startValue, s, path);
        path = "";
        string t;
        f(n, destValue, t, path);
        //cout << n->val << " " << s << " " << t << endl;
        string ans = string(s.size(), 'U') + t;
        return ans;
    }

private:
    TreeNode *lca(TreeNode *root, int s, int t) {
        if(!root)
            return root;
        int v = root->val;
        if(v == s || v == t)
            return root;

        TreeNode *l = lca(root->left, s, t);
        TreeNode *r = lca(root->right, s, t);
        if(l && r)
            return root;
        return l ? l : r;
    }

    void f(TreeNode *root, int t, string &ans, string &p) {
        if(!root)
            return;
        if(root->val == t) {
            ans = p;
            return;
        }

        if(root->left) {
            p.push_back('L');
            f(root->left, t, ans, p);
            p.pop_back();
        }
        if(root->right) {
            p.push_back('R');
            f(root->right, t, ans, p);
            p.pop_back();
        }
    }
};
