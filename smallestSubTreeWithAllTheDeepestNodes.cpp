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
    unordered_map<TreeNode*, int> d;
    int maxDepth(TreeNode* root){
        if(!root)
            return 0;
        if(d.find(root) == d.end())
            return d[root] = 1 + max(maxDepth(root->left), maxDepth(root->right));
        return d[root];
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)
            return NULL;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        if(l == r)
            return root;
        else if(l < r)
            return subtreeWithAllDeepest(root->right);
        else
            return subtreeWithAllDeepest(root->left);
    }
};
