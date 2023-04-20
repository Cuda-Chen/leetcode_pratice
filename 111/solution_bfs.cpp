class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
       
        queue<TreeNode *> q{{root}};
        int depth = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto t = q.front();
                q.pop();
                if(!t->left && !t->right)
                    return depth;
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            depth++;
        }
        return -1;
    }
};
