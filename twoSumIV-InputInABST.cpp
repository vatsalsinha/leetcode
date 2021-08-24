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
    vector<int> v;
    void dfs(TreeNode* root){
        if(!root)
            return;
        v.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        unordered_map<int, int> umap; // nums[i] : i
        for(int i =0; i < v.size(); i++){
            if(umap.find(k-v[i]) != umap.end())
                return true;
            umap[v[i]] = i;
        }
        return false;
    }
};
