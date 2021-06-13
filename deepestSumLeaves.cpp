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
    int maxDepth;
    int maxD(TreeNode* root){
        if(root == NULL)
            return 0;
        return 1 + max(maxD(root->left), maxD(root->right));
    }
    int sum(TreeNode* root, int depth){
        if(root == NULL)
            return 0;
        if(depth == maxDepth-1)
            return root->val;
        return sum(root->left, depth+1) + sum(root->right, depth+1);
        //get last leftnode + get last Rightnode
    }
    int deepestLeavesSum(TreeNode* root) {
        maxDepth = maxD(root);
        return sum(root, 0);
    }
};
