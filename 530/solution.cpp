// level-order traversal then sort

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
    int getMinimumDifference(TreeNode* root) {
        vector<int> tmp;
        queue<TreeNode *> q{{root}};
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            tmp.push_back(t->val);
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }

        sort(begin(tmp), end(tmp));

        int ans = INT_MAX;
        for(int i = 1; i < tmp.size(); i++) {
            int diff = tmp[i] - tmp[i - 1];
            ans = min(ans, diff);
        }
        return ans;
    }
};
