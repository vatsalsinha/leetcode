/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void inorder(TreeNode* root, TreeNode* target, TreeNode* &ans){
        if(root == NULL)
            return;
        if(root->val == target->val)
            ans = root;
        inorder(root->left, target, ans);
        inorder(root->right, target, ans);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans;
        inorder(cloned, target, ans);
        return ans;
    }
};
