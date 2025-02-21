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
class FindElements {
public:
    FindElements(TreeNode* root) {
        f(root, 0);
    }
    
    bool find(int target) {
        return m.count(target);
    }

private:
    TreeNode *root;

    void f(TreeNode *t, int idx) {
        if(!t)
            return;
        m.insert(idx);
        f(t->left, idx * 2 + 1);
        f(t->right, idx * 2 + 2);
    }

    unordered_set<int> m;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
