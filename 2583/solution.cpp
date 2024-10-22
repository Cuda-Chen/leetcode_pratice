// level-order traversal

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> q;
        queue<TreeNode *> qq{{root}};
        while(!qq.empty()) {
            int sz = qq.size();
            long long sum = 0;
            while(sz--) {
                TreeNode *t = qq.front();
                qq.pop();
                sum += t->val;
                if(t->left)
                    qq.push(t->left);
                if(t->right)
                    qq.push(t->right);
            }
            q.push(sum);
        }
        while(!q.empty() && --k)
            q.pop();
        return q.empty() ? -1 : q.top();
    }
};
