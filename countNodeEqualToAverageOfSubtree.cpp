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
    int sum_tree(TreeNode* root){
        if(!root)
            return 0;
        return root->val + sum_tree(root->left) + sum_tree(root->right);
    }
    int getsize(TreeNode* root){
        if(!root)
            return 0;
        return 1 + getsize(root->left) + getsize(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root)
            return 0;
        int c = root->val == sum_tree(root)/getsize(root) ? 1 : 0;
        return c + averageOfSubtree(root->left) + averageOfSubtree(root->right);
    }
};
