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
    int sum = 0;
    // idea is to traverse inorder, but from the right
    TreeNode* bstToGst(TreeNode* root) {
        if(root != NULL){
            bstToGst(root->right);
            sum = root->val += sum;
            bstToGst(root->left);
        }
        return root;
    }
};
