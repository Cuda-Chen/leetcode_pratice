class Solution {
public:
    string tree2str(TreeNode* root) {
        string ans;
        helper(root, ans);
        return ans;
    }

private:
    void helper(TreeNode *root, string &ans) {
        if(!root)
            return;

        ans += to_string(root->val);
        if(!root->left && !root->right)
            return;

        ans += "(";
        helper(root->left, ans);
        ans += ")";
        if(!root->right)
            return;

        ans += "(";
        helper(root->right, ans);
        ans += ")";
    }
};
