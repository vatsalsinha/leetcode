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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        flatten(root->left); // reach the last left node
        TreeNode* right = root->right;
        root->right = root->left; // attach left child to right
        root->left = NULL; // have the left child 
        while(root->right) // go to the bottom of newly created root
            root = root->right;
        flatten(right); // reach the bottom most left node 
        root->right = right; // attach the og right child to new bottom right child
    }
};
