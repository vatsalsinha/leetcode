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
    vector<int> in;
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
    
    TreeNode* construct(int left, int right){
        if(left > right)
            return NULL;
        int mid = (left+right) / 2;
        TreeNode* root = new TreeNode(in[mid]);
        root->left = construct(left, mid-1);
        root->right = construct(mid+1, right);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        //get inorder traversal
        //construct tree from inorder traversal
        inorder(root);
        return construct(0, in.size()-1);
    }
};
