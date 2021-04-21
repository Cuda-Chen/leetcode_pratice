// queue

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int result = 1;
        queue<Node *> current, next;
        current.push(root);
        while(!current.empty()) {
            // traverse the current queue 
            while(!current.empty()) {
                Node *node = current.front();
                for(auto child : node->children)
                    next.push(child);
                current.pop();
            }
            
            // if current level's nodes are all popped 
            // and next level's nodes exist
            if(current.empty() && !next.empty()) result++;
            
            // push all next level's nodes
            // to current level's queue
            while(!next.empty()) {
                current.push(next.front());
                next.pop();
            }
        }
        return result;
    }
};
