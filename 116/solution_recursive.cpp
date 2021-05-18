// https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-1/er-cha-shu-xi-lie-1#san-suan-fa-shi-jian
// recursive
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        helper(root->left, root->right);
        return root;
    }
    
private:
    void helper(Node *l, Node *r) {
        if(!l || !r) return;
        
        l->next = r;
        
        helper(l->left, l->right);
        helper(r->left, r->right);
        helper(l->right, r->left);
    }
};
