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
    unordered_map<TreeNode*,int> depth; // helps in optimising time limit
    int maxDepth(TreeNode* root){
        if(!root)
            return 0;
        if(!depth.count(root))
            depth[root] =  1 + max(maxDepth(root->left), maxDepth(root->right));
        return depth[root];
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root)
            return NULL;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        if(l == r)
            return root;
        else if(l < r)
            return lcaDeepestLeaves(root->right);
        else
            return lcaDeepestLeaves(root->left);
    }
};
