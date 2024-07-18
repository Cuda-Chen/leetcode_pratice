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
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode *, unordered_set<TreeNode *>> g;
        unordered_set<TreeNode *> leaves;
        build(root, nullptr, g, leaves);

        int ans = 0;
        for(auto u : leaves) {
            queue<TreeNode *> q;
            unordered_set<TreeNode *> seen;
            int tmp = distance + 1;
            q.push(u);
            while(tmp--) {
                int sz = q.size();
                while(sz--) {
                    auto t = q.front();
                    q.pop();
                    if(leaves.count(t) && t != u)
                        ans++;
                    if(seen.count(t))
                        continue;
                    seen.insert(t);
                    for(auto v : g[t])
                        q.push(v);
                }
            }
        }
        return ans / 2;
    }

private:
    void build(
        TreeNode *root,
        TreeNode *p,
        unordered_map<TreeNode *, unordered_set<TreeNode *>> &g,
        unordered_set<TreeNode *> &leaves
    ) {
        if(!root)
            return;

        if(!g.count(root))
            g[root] = {};
        if(p) {
            g[p].insert(root);
            g[root].insert(p);
        }
        if(!root->left && !root->right) {
            leaves.insert(root);
            return;
        }
        if(root->left)
            build(root->left, root, g, leaves);
        if(root->right)
            build(root->right, root, g, leaves);
    }

    void dfs(
        unordered_map<TreeNode *, unordered_set<TreeNode *>> &g,
        TreeNode *u,
        TreeNode *v,
        unordered_set<TreeNode *> &seen,
        int &ans,
        int d
    ) {
        if(seen.count(u))
            return;
        if(d < 0)
            return;
        if(u == v) {
            if(d >= 0)
                ans++;
            return;
        }

        seen.insert(u);
        d--;
        for(auto w : g[u])
            dfs(g, w, v, seen, ans, d);
    }
};
