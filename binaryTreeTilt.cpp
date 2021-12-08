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
    int findSum(TreeNode* root){
        if(!root)
            return 0;
        return root->val + findSum(root->left) + findSum(root->right);
    }
    int findTilt(TreeNode* root) {
        if(!root)
            return 0;
        sum += abs(findSum(root->left) - findSum(root->right));
        findTilt(root->left) + findTilt(root->right);
        return sum;
    }
};
