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
    int steps = 0;
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        steps += abs(left) + abs(right);
        return root->val + left + right - 1; // 1 for the root
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return steps;
    }
};
