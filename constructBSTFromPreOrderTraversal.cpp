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
    TreeNode* helper(vector<int> preorder, int& start, int bound){
        if(start == preorder.size() || preorder[start] > bound)
            return NULL;
        TreeNode* root = new TreeNode(preorder[start++]);
        root->left = helper(preorder, start, root->val);
        root->right = helper(preorder, start, bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int start = 0;
        return helper(preorder, start, INT_MAX);
    }
};
