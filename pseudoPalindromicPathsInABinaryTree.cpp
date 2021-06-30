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
    int count = 0;
    void dfs(TreeNode* root, bitset<9> b){
        if(root){
            b.flip(root->val - 1); // indexing starts with 0;
            if(!root->left && !root->right){
                if(b.count() <= 1){ // a palindrome can have atmost 1 number with odd frequency.
                    count++;
                    return;
                }
            }
            dfs(root->left, b);
            dfs(root->right, b);
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        bitset<9> b;
        dfs(root, b);
        return count; 
    }
};
