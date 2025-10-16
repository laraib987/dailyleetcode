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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) 
            return 0;  // base case: empty tree has depth 0
        
        int leftDepth = maxDepth(root->left);   // find depth of left subtree
        int rightDepth = maxDepth(root->right); // find depth of right subtree
        
        return 1 + max(leftDepth, rightDepth); 
        
    }
};