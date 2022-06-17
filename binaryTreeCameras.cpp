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
    /* 
    Here we follow the bottom up approach. 
    any node can have 3 states:
        1. it is covered by the camera 0
        2. it itself is a camera ie 1
        3. it requires a camera ie -1
    start filling in the camera from the leaf nodes. 
    */
    int count = 0;
    int solve(TreeNode* root){
        if(!root)
            return 1;
        int l = solve(root->left);
        int r = solve(root->right);
        if(l == -1 || r == -1){
            count++;
            return 0;
        }
        if(l == 0 || r == 0)
            return 1;
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if(solve(root) == -1)
            count++;
        return count;
    }
};
