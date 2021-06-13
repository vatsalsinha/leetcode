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
    int res = 0;
   void helper(TreeNode *root, TreeNode *parent, TreeNode *gParent){
        if(root){
            if(gParent!=NULL && (gParent->val%2 == 0)){
                res += root->val;
            }
            helper(root->left, root, parent);
            helper(root->right, root, parent);
        }
    }

    int sumEvenGrandparent(TreeNode* root) {
        helper(root, NULL, NULL);
        return res;
    }
};
