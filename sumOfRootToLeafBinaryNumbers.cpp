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
    int sum = 0;
    int convert(string num){
        return stoi(num, 0, 2);
    }
    void helper(TreeNode* root, string curr){
        if(!root)
            return;
        curr += to_string(root->val);
        helper(root->left, curr);
        helper(root->right, curr);
        if(root->left == NULL && root->right == NULL){
            sum += convert(curr);
            
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        helper(root, "");
        return sum;
    }
};
