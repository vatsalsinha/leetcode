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
vector<int> v1, v2;
    void getLeaf(TreeNode* root, vector<int>& v){
        if(!root)
            return;
        if(!root->left && !root->right)
            v.push_back(root->val);
        getLeaf(root->left, v);
        getLeaf(root->right, v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        getLeaf(root1, v1);
        getLeaf(root2, v2);
        return v1 == v2;
    }
};
