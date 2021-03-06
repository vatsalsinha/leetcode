

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
    unordered_map<string, int> dict;
    string dfs(TreeNode* root, vector<TreeNode*> &v){
        if(root == NULL)
            return "#";
        string left = dfs(root->left, v);
        string right = dfs(root->right, v);
        string str;
        str = to_string(root->val)+","+left+","+right;
        dict[str]++;
        if(dict[str] == 2)
            v.push_back(root);
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> v;
        dfs(root, v);
        return v;
    }
};
