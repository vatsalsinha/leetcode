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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* t = new TreeNode(val);
            return t;
        }
        TreeNode* tmp = root;
        while(tmp){
            if(tmp->val < val){
                if(tmp->right)
                    tmp = tmp->right;
                else{
                    TreeNode* d = new TreeNode(val);
                    tmp->right = d;
                    break;
                }
            }
            else{
                if(tmp->left)
                    tmp = tmp->left;
                else{
                    TreeNode* d = new TreeNode(val);
                    tmp->left = d;
                    break;
                }
            }
        }
        return root;
    }
};
