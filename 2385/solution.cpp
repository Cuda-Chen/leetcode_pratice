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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> g;
        build_graph(root, nullptr, g);

        int ans = -1;
        queue<int> q{{start}};
        unordered_set<int> seen;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int v = q.front();
                q.pop();

                seen.insert(v);
                for(int u : g[v]) {
                    if(!seen.count(u))
                        q.push(u);
                }
            }
            ans++;
        }
        return ans;
    }

private:
    void build_graph(
        TreeNode *root,
        TreeNode *p,
        unordered_map<int, vector<int>> &g
    ) {
        if(!root)
            return;

        int v = root->val;
        if(!g.count(v))
            g[v] = {};

        if(p) {
            g[v].push_back(p->val);
            g[p->val].push_back(v);
        }
        if(root->left)
            build_graph(root->left, root, g);
        if(root->right)
            build_graph(root->right, root, g);
    }
};
