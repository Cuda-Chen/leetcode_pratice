class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        helper(root, low, high, ans);
        return ans;
    }

private:
    void helper(TreeNode *root, int low, int high, int &ans){
        if(!root)
            return;

        int v = root->val;
        if(low <= v && v <= high)
            ans += v;
        if(v >= low)
            helper(root->left, low, high, ans);
        if(v <= high)
            helper(root->right, low, high, ans);
    }
};
