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
    int maxDepth(TreeNode*  root){
        if(root == NULL)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    int findBottomLeftValue(TreeNode* root) {
        int depth = maxDepth(root);
        queue<TreeNode*> q;
        q.push(root);
        int curLevel = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* t = q.front();
                if(curLevel == depth)
                    return t->val; // this gives left val cuz we are always pushing left subtree first
                q.pop();
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            curLevel++;
        }
        return 0;
    }
};
