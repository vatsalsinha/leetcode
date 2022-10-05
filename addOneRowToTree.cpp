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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            level++;
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
                if(level == depth-1){
                    TreeNode* node = new TreeNode(val);
                    TreeNode* l = tmp->left;
                    TreeNode* r = tmp->right;
                    tmp->left = node;
                    node->left = l;
                    tmp->right = new TreeNode(val);
                    tmp->right->right = r;
                }
            }
        }
        return root;
    }
};
