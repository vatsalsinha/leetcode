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
    vector<int> dfs(TreeNode* root){
        if(!root)
            return vector<int> (2, 0);
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        vector<int> res(2);
        res[0] = max(left[0] , left[1]) + max(right[0], right[1]); // root not robbed
        res[1] = root->val + left[0] + right[0]; //root robbed
        return res;
    }
    int rob(TreeNode* root) {
        vector<int> res= dfs(root);
        return max(res[0], res[1]);
            
    }
};
