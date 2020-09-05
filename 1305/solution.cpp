// Just traverse each tree then combine the array and sorting
// traverse code refer from here:
// http://alrightchiu.github.io/SecondRound/binary-tree-traversalxun-fang.html

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> array1;
        vector<int> array2;
        traverse(root1, array1);
        traverse(root2, array2);
        
        vector<int> array;
        array.reserve(array1.size() + array2.size());
        array.insert(array.end(), array1.begin(), array1.end());
        array.insert(array.end(), array2.begin(), array2.end());
        
        sort(array.begin(), array.end());
        
        return array;
    }
    
private:
    void traverse(TreeNode *root, vector<int> &records) {
        if(root) {
            traverse(root->left, records);
            records.push_back(root->val);
            traverse(root->right, records);
        }
    }
};
