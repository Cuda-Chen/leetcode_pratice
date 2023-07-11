// inorder + DFS

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, unordered_set<int>> g;
        inorder(root, nullptr, g);
        vector<int> ans;
        queue<int> q{{target->val}};
        unordered_set<int> seen;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto u = q.front();
                q.pop();
                seen.insert(u);
                if(k == 0)
                    ans.push_back(u);
                for(auto v : g[u]) {
                    if(!seen.count(v))
                        q.push(v);
                }
            }
            if(k == 0)
                break;
            k--;
        }
        return ans;
    }

private:
    void inorder(
        TreeNode *root,
        TreeNode *prev, 
        unordered_map<int, unordered_set<int>> &g
    ) {
        if(!root)
            return;
        if(prev)
            push(root->val, prev->val, g);
        if(root->left)
            push(root->val, root->left->val, g);
        if(root->right)
            push(root->val, root->right->val, g);
        inorder(root->left, root, g);
        inorder(root->right, root, g);
    }

    void push(
        int u,
        int v,
        unordered_map<int, unordered_set<int>> &g
    ) {
        if(!g.count(u))
            g[u] = unordered_set<int>();
        if(!g.count(v))
            g[v] = unordered_set<int>();
        g[u].insert(v);
        g[v].insert(u);
    }
};
