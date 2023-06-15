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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> q{{root}};
        int ans = INT_MIN, ans_idx = -1, idx = 1;
        while(!q.empty()) {
            int sz = q.size();
            vector<int> tmp;
            while(sz--) {
                auto t = q.front();
                q.pop();
                tmp.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            int sum = std::accumulate(begin(tmp), end(tmp), 0);
            if(ans < sum) {
                ans = sum;
                ans_idx = idx;
            }
            idx++;
        }
        return ans_idx;
    }
};
