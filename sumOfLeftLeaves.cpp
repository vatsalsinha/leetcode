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
    int dfs(TreeNode* root, bool isleft = false){
        if (!root) return 0;
        if (!root->left && !root->right) return isleft ? root->val : 0;
        return dfs(root->left, true) + dfs(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        //efficient dfs method
        return dfs(root);
        //bfs method
        // queue<TreeNode*> q;
        // q.push(root);
        // int sum = 0;
        // while(!q.empty()){
        //     int sz = q.size();
        //     while(sz--){
        //         auto cur = q.front();
        //         q.pop();
        //         if(cur->left == NULL && cur->right == NULL && cur != root){
        //             sum += cur->val;
        //         }
        //         if(cur->left){
        //             q.push(cur->left);
        //         }
        //         if(cur->right){
        //             if(cur->right->left != NULL || cur->right->right != NULL)
        //                 q.push(cur->right);
        //         }
        //     }
        // }
        // return sum;
    }
};
